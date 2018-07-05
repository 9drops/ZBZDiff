
  Pod::Spec.new do |s|
  s.name         = "txdiff"
  s.version      = "1.0.0"
  s.summary      = "A lightweight compare diffent library"

  s.description  = <<-DESC
                    A lightweight compare diffent library
                   DESC

  s.homepage     = "https://github.com/9drops/txdiff"
  s.license      = "MIT"
  s.author             = { "drops" => "zhanbz@qq.com" }
  s.social_media_url   = "http://www.up366.com"

  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/9drops/txdiff.git", :tag => s.version }

  s.source_files  = "txdiff.h", "txdiff.c"
  s.public_header_files = "txdiff.h"
  s.requires_arc = true

end
