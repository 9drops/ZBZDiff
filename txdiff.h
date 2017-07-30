#ifndef __txdiff_h__
#define __txdiff_h__

#ifdef __cplusplus
	extern "C" {
#endif
		
/**
 * 比较2个文件（或目录）是否相同
 * is_compare_file_content - 如果文件字节数相同是否比较文件内容
 * return 0 - 相同，非0 - 不同
 */
        int txdiff(const char *path1, const char *path2, char is_compare_file_content);

#ifdef __cplusplus
	}
#endif

#endif
