; Auto-generated. Do not edit!


(cl:in-package skeleton_markers-srv)


;//! \htmlinclude skeleton_listener_service-request.msg.html

(cl:defclass <skeleton_listener_service-request> (roslisp-msg-protocol:ros-message)
  ((randomArr
    :reader randomArr
    :initarg :randomArr
    :type cl:integer
    :initform 0)
   (randomGes
    :reader randomGes
    :initarg :randomGes
    :type cl:integer
    :initform 0)
   (state
    :reader state
    :initarg :state
    :type cl:integer
    :initform 0))
)

(cl:defclass skeleton_listener_service-request (<skeleton_listener_service-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <skeleton_listener_service-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'skeleton_listener_service-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name skeleton_markers-srv:<skeleton_listener_service-request> is deprecated: use skeleton_markers-srv:skeleton_listener_service-request instead.")))

(cl:ensure-generic-function 'randomArr-val :lambda-list '(m))
(cl:defmethod randomArr-val ((m <skeleton_listener_service-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader skeleton_markers-srv:randomArr-val is deprecated.  Use skeleton_markers-srv:randomArr instead.")
  (randomArr m))

(cl:ensure-generic-function 'randomGes-val :lambda-list '(m))
(cl:defmethod randomGes-val ((m <skeleton_listener_service-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader skeleton_markers-srv:randomGes-val is deprecated.  Use skeleton_markers-srv:randomGes instead.")
  (randomGes m))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <skeleton_listener_service-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader skeleton_markers-srv:state-val is deprecated.  Use skeleton_markers-srv:state instead.")
  (state m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <skeleton_listener_service-request>) ostream)
  "Serializes a message object of type '<skeleton_listener_service-request>"
  (cl:let* ((signed (cl:slot-value msg 'randomArr)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'randomGes)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'state)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <skeleton_listener_service-request>) istream)
  "Deserializes a message object of type '<skeleton_listener_service-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'randomArr) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'randomGes) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'state) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<skeleton_listener_service-request>)))
  "Returns string type for a service object of type '<skeleton_listener_service-request>"
  "skeleton_markers/skeleton_listener_serviceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'skeleton_listener_service-request)))
  "Returns string type for a service object of type 'skeleton_listener_service-request"
  "skeleton_markers/skeleton_listener_serviceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<skeleton_listener_service-request>)))
  "Returns md5sum for a message object of type '<skeleton_listener_service-request>"
  "02ed10f1db63e4153feab56164fcc314")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'skeleton_listener_service-request)))
  "Returns md5sum for a message object of type 'skeleton_listener_service-request"
  "02ed10f1db63e4153feab56164fcc314")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<skeleton_listener_service-request>)))
  "Returns full string definition for message of type '<skeleton_listener_service-request>"
  (cl:format cl:nil "int64 randomArr~%int64 randomGes~%int64 state~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'skeleton_listener_service-request)))
  "Returns full string definition for message of type 'skeleton_listener_service-request"
  (cl:format cl:nil "int64 randomArr~%int64 randomGes~%int64 state~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <skeleton_listener_service-request>))
  (cl:+ 0
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <skeleton_listener_service-request>))
  "Converts a ROS message object to a list"
  (cl:list 'skeleton_listener_service-request
    (cl:cons ':randomArr (randomArr msg))
    (cl:cons ':randomGes (randomGes msg))
    (cl:cons ':state (state msg))
))
;//! \htmlinclude skeleton_listener_service-response.msg.html

(cl:defclass <skeleton_listener_service-response> (roslisp-msg-protocol:ros-message)
  ((flag
    :reader flag
    :initarg :flag
    :type cl:boolean
    :initform cl:nil)
   (success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass skeleton_listener_service-response (<skeleton_listener_service-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <skeleton_listener_service-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'skeleton_listener_service-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name skeleton_markers-srv:<skeleton_listener_service-response> is deprecated: use skeleton_markers-srv:skeleton_listener_service-response instead.")))

(cl:ensure-generic-function 'flag-val :lambda-list '(m))
(cl:defmethod flag-val ((m <skeleton_listener_service-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader skeleton_markers-srv:flag-val is deprecated.  Use skeleton_markers-srv:flag instead.")
  (flag m))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <skeleton_listener_service-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader skeleton_markers-srv:success-val is deprecated.  Use skeleton_markers-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <skeleton_listener_service-response>) ostream)
  "Serializes a message object of type '<skeleton_listener_service-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'flag) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <skeleton_listener_service-response>) istream)
  "Deserializes a message object of type '<skeleton_listener_service-response>"
    (cl:setf (cl:slot-value msg 'flag) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<skeleton_listener_service-response>)))
  "Returns string type for a service object of type '<skeleton_listener_service-response>"
  "skeleton_markers/skeleton_listener_serviceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'skeleton_listener_service-response)))
  "Returns string type for a service object of type 'skeleton_listener_service-response"
  "skeleton_markers/skeleton_listener_serviceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<skeleton_listener_service-response>)))
  "Returns md5sum for a message object of type '<skeleton_listener_service-response>"
  "02ed10f1db63e4153feab56164fcc314")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'skeleton_listener_service-response)))
  "Returns md5sum for a message object of type 'skeleton_listener_service-response"
  "02ed10f1db63e4153feab56164fcc314")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<skeleton_listener_service-response>)))
  "Returns full string definition for message of type '<skeleton_listener_service-response>"
  (cl:format cl:nil "bool flag~%bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'skeleton_listener_service-response)))
  "Returns full string definition for message of type 'skeleton_listener_service-response"
  (cl:format cl:nil "bool flag~%bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <skeleton_listener_service-response>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <skeleton_listener_service-response>))
  "Converts a ROS message object to a list"
  (cl:list 'skeleton_listener_service-response
    (cl:cons ':flag (flag msg))
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'skeleton_listener_service)))
  'skeleton_listener_service-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'skeleton_listener_service)))
  'skeleton_listener_service-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'skeleton_listener_service)))
  "Returns string type for a service object of type '<skeleton_listener_service>"
  "skeleton_markers/skeleton_listener_service")