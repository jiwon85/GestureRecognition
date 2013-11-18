FILE(REMOVE_RECURSE
  "../msg_gen"
  "../srv_gen"
  "../src/skeleton_markers/msg"
  "../src/skeleton_markers/srv"
  "CMakeFiles/skeleton_tracker.dir/src/skeleton_tracker.cpp.o"
  "CMakeFiles/skeleton_tracker.dir/src/KinectController.cpp.o"
  "CMakeFiles/skeleton_tracker.dir/src/KinectDisplay.cpp.o"
  "../bin/skeleton_tracker.pdb"
  "../bin/skeleton_tracker"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/skeleton_tracker.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
