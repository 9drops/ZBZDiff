
  Pod::Spec.new do |s|
  s.name         = "zbzdiff"
  s.version      = "1.0.0"
  s.summary      = "A lightweight compare diffent library"

  s.description  = <<-DESC
                    A lightweight compare diffent library, md5 comparation is option
                   DESC

  s.homepage     = "https://github.com/9drops/zbzdiff"
  s.license = { :type => 'MIT', :text => <<-LICENSE
         Copyright zbz 2022
          LICENSE
      }
      
  s.author             = { "drops" => "zhanbz@qq.com" }
  s.social_media_url   = "http:///github.com/9drops"

  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/9drops/zbzdiff.git", :tag => s.version }

  s.source_files  = "zbzdiff.h", "zbzdiff.c"
  s.public_header_files = "zbzdiff.h"
  s.requires_arc = true

end
