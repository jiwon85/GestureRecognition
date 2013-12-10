
(cl:in-package :asdf)

(defsystem "skeleton_markers-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "skeleton_listener_service" :depends-on ("_package_skeleton_listener_service"))
    (:file "_package_skeleton_listener_service" :depends-on ("_package"))
  ))