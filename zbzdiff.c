#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/uio.h>

#define return_msg(ret, msg...) \
    do{fprintf(stderr, ##msg);return ret;}while(0)

/**
* comapre two files
* return 0 - same, other - not same
*/
static int compare_reg_files(const char *file1, const char *file2) {
    ssize_t c1, c2;
	int fd1, fd2;
	char buf1, buf2; 
	
    if ((fd1= open(file1, O_RDONLY)) == -1 ) { 
	    return_msg(-1, "open error\n");
    } 

    if ((fd2= open(file2, O_RDONLY)) == -1 ) { 
        close(fd1); 
	    return_msg(-1, "open(%s) error\n", file2);
    } 

    c1= read(fd1, &buf1, 1); 
    c2= read(fd2, &buf2, 1); 
     while (c1 != 0 && c2 != 0) { 
        if (buf1 != buf2)  break; 
        c1= read(fd1, &buf1, 1); 
        c2= read(fd2, &buf2, 1); 
    } 

    close(fd1); 
    close(fd2); 
    if ( c1 == 0 && c2 == 0 ) /*two files same*/ 
	    return 0;
	return 1; 
} 


int zbzdiff(const char *path1, const char *path2, char is_compare_file_content) {
    char tmp1[1024], tmp2[1024];
    const char *file;
    DIR *dir, *dir2;
    struct dirent *p, *q;
    struct stat st1, st2;
    
    if (!path1 || !path2)
        return 1;
    
    if (stat(path1, &st1) || stat(path2, &st2)) {
        return -1;
    }
    
    if (st1.st_mode != st2.st_mode)
        return 1;
    else if (S_ISREG(st1.st_mode) && (st1.st_size != st2.st_size || (is_compare_file_content && compare_reg_files(path1, path2)))) {
        return 1;
    } else if (S_ISDIR(st1.st_mode) && S_ISDIR(st2.st_mode)) {
        if (NULL == (dir = opendir(path1)) || (NULL == (dir2 = opendir(path2)))) {
            return_msg(-1, "opendir() error\n");
        }
        
        while ((p = readdir(dir))) {
            q = readdir(dir2);
            file = p->d_name;
            if (0 == strcmp(file, ".") || 0 == strcmp(file, "..") || 0 == strcmp(file, ".DS_Store"))
                continue;
            snprintf(tmp1, sizeof(tmp1), "%s/%s", path1, file);
            snprintf(tmp2, sizeof(tmp2), "%s/%s", path2, file);
            if (zbzdiff(tmp1, tmp2, is_compare_file_content))
                return 1;
        }
        
        closedir(dir);
        if ((q = readdir(dir2))) {
            closedir(dir2);
            return 1;
        } else
            closedir(dir2);
        
    }
    
    return 0;
}

#if 1 
int main(int argc, char **argv) {
    if (argc < 3) {
        return_msg(-1, "usage:%s path1 path2\n", argv[0]);
    }

	int res = zbzdiff(argv[1], argv[2], 0);
	printf("diff:%d\n", res);
	return 0;
}
#endif
