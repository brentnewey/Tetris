#include "generate.h"
#include "pipe.h"

void InitializeTetrads(){

  tetrad_definitions[tetrad_cross].orientations[base].s1x = -1;
  tetrad_definitions[tetrad_cross].orientations[base].s1y = 0;
  tetrad_definitions[tetrad_cross].orientations[base].s2x = 1;
  tetrad_definitions[tetrad_cross].orientations[base].s2y = 0;
  tetrad_definitions[tetrad_cross].orientations[base].s3x = 0;
  tetrad_definitions[tetrad_cross].orientations[base].s3y = 1;

  tetrad_definitions[tetrad_cross].orientations[clockwise].s1x = 0;
  tetrad_definitions[tetrad_cross].orientations[clockwise].s1y = -1;
  tetrad_definitions[tetrad_cross].orientations[clockwise].s2x = 1;
  tetrad_definitions[tetrad_cross].orientations[clockwise].s2y = 0;
  tetrad_definitions[tetrad_cross].orientations[clockwise].s3x = 0;
  tetrad_definitions[tetrad_cross].orientations[clockwise].s3y = 1;

  tetrad_definitions[tetrad_cross].orientations[flipped].s1x = 0;
  tetrad_definitions[tetrad_cross].orientations[flipped].s1y = -1;
  tetrad_definitions[tetrad_cross].orientations[flipped].s2x = -1;
  tetrad_definitions[tetrad_cross].orientations[flipped].s2y = 0;
  tetrad_definitions[tetrad_cross].orientations[flipped].s3x = 1;
  tetrad_definitions[tetrad_cross].orientations[flipped].s3y = 0;

  tetrad_definitions[tetrad_cross].orientations[counter_clockwise].s1x = 0;
  tetrad_definitions[tetrad_cross].orientations[counter_clockwise].s1y = -1;
  tetrad_definitions[tetrad_cross].orientations[counter_clockwise].s2x = -1;
  tetrad_definitions[tetrad_cross].orientations[counter_clockwise].s2y = 0;
  tetrad_definitions[tetrad_cross].orientations[counter_clockwise].s3x = 0;
  tetrad_definitions[tetrad_cross].orientations[counter_clockwise].s3y = 1;

  tetrad_definitions[tetrad_cross].cx = 4;
  tetrad_definitions[tetrad_cross].cy = 0;

  tetrad_definitions[tetrad_line].orientations[base].s1x = -1;
  tetrad_definitions[tetrad_line].orientations[base].s1y = 0;
  tetrad_definitions[tetrad_line].orientations[base].s2x = 1;
  tetrad_definitions[tetrad_line].orientations[base].s2y = 0;
  tetrad_definitions[tetrad_line].orientations[base].s3x = 2;
  tetrad_definitions[tetrad_line].orientations[base].s3y = 0;

  tetrad_definitions[tetrad_line].orientations[clockwise].s1x = 0;
  tetrad_definitions[tetrad_line].orientations[clockwise].s1y = -1;
  tetrad_definitions[tetrad_line].orientations[clockwise].s2x = 0;
  tetrad_definitions[tetrad_line].orientations[clockwise].s2y = 1;
  tetrad_definitions[tetrad_line].orientations[clockwise].s3x = 0;
  tetrad_definitions[tetrad_line].orientations[clockwise].s3y = 2;

  tetrad_definitions[tetrad_line].orientations[flipped].s1x = -1;
  tetrad_definitions[tetrad_line].orientations[flipped].s1y = 0;
  tetrad_definitions[tetrad_line].orientations[flipped].s2x = 1;
  tetrad_definitions[tetrad_line].orientations[flipped].s2y = 0;
  tetrad_definitions[tetrad_line].orientations[flipped].s3x = 2;
  tetrad_definitions[tetrad_line].orientations[flipped].s3y = 0;

  tetrad_definitions[tetrad_line].orientations[counter_clockwise].s1x = 0;
  tetrad_definitions[tetrad_line].orientations[counter_clockwise].s1y = -1;
  tetrad_definitions[tetrad_line].orientations[counter_clockwise].s2x = 0;
  tetrad_definitions[tetrad_line].orientations[counter_clockwise].s2y = 1;
  tetrad_definitions[tetrad_line].orientations[counter_clockwise].s3x = 0;
  tetrad_definitions[tetrad_line].orientations[counter_clockwise].s3y = 2;

  tetrad_definitions[tetrad_line].cx = 4;
  tetrad_definitions[tetrad_line].cy = 0;

  tetrad_definitions[tetrad_square].orientations[base].s1x = 1;
  tetrad_definitions[tetrad_square].orientations[base].s1y = 0;
  tetrad_definitions[tetrad_square].orientations[base].s2x = 0;
  tetrad_definitions[tetrad_square].orientations[base].s2y = 1;
  tetrad_definitions[tetrad_square].orientations[base].s3x = 1;
  tetrad_definitions[tetrad_square].orientations[base].s3y = 1;

  tetrad_definitions[tetrad_square].orientations[clockwise].s1x = 1;
  tetrad_definitions[tetrad_square].orientations[clockwise].s1y = 0;
  tetrad_definitions[tetrad_square].orientations[clockwise].s2x = 0;
  tetrad_definitions[tetrad_square].orientations[clockwise].s2y = 1;
  tetrad_definitions[tetrad_square].orientations[clockwise].s3x = 1;
  tetrad_definitions[tetrad_square].orientations[clockwise].s3y = 1;

  tetrad_definitions[tetrad_square].orientations[flipped].s1x = 1;
  tetrad_definitions[tetrad_square].orientations[flipped].s1y = 0;
  tetrad_definitions[tetrad_square].orientations[flipped].s2x = 0;
  tetrad_definitions[tetrad_square].orientations[flipped].s2y = 1;
  tetrad_definitions[tetrad_square].orientations[flipped].s3x = 1;
  tetrad_definitions[tetrad_square].orientations[flipped].s3y = 1;

  tetrad_definitions[tetrad_square].orientations[counter_clockwise].s1x = 1;
  tetrad_definitions[tetrad_square].orientations[counter_clockwise].s1y = 0;
  tetrad_definitions[tetrad_square].orientations[counter_clockwise].s2x = 0;
  tetrad_definitions[tetrad_square].orientations[counter_clockwise].s2y = 1;
  tetrad_definitions[tetrad_square].orientations[counter_clockwise].s3x = 1;
  tetrad_definitions[tetrad_square].orientations[counter_clockwise].s3y = 1;

  tetrad_definitions[tetrad_square].cx = 4;
  tetrad_definitions[tetrad_square].cy = 0;

  tetrad_definitions[tetrad_z].orientations[base].s1x = -1;
  tetrad_definitions[tetrad_z].orientations[base].s1y = 0;
  tetrad_definitions[tetrad_z].orientations[base].s2x = 0;
  tetrad_definitions[tetrad_z].orientations[base].s2y = 1;
  tetrad_definitions[tetrad_z].orientations[base].s3x = 1;
  tetrad_definitions[tetrad_z].orientations[base].s3y = 1;

  tetrad_definitions[tetrad_z].orientations[clockwise].s1x = 1;
  tetrad_definitions[tetrad_z].orientations[clockwise].s1y = -1;
  tetrad_definitions[tetrad_z].orientations[clockwise].s2x = 1;
  tetrad_definitions[tetrad_z].orientations[clockwise].s2y = 0;
  tetrad_definitions[tetrad_z].orientations[clockwise].s3x = 0;
  tetrad_definitions[tetrad_z].orientations[clockwise].s3y = 1;

  tetrad_definitions[tetrad_z].orientations[flipped].s1x = -1;
  tetrad_definitions[tetrad_z].orientations[flipped].s1y = 0;
  tetrad_definitions[tetrad_z].orientations[flipped].s2x = 0;
  tetrad_definitions[tetrad_z].orientations[flipped].s2y = 1;
  tetrad_definitions[tetrad_z].orientations[flipped].s3x = 1;
  tetrad_definitions[tetrad_z].orientations[flipped].s3y = 1;

  tetrad_definitions[tetrad_z].orientations[counter_clockwise].s1x = 1;
  tetrad_definitions[tetrad_z].orientations[counter_clockwise].s1y = -1;
  tetrad_definitions[tetrad_z].orientations[counter_clockwise].s2x = 1;
  tetrad_definitions[tetrad_z].orientations[counter_clockwise].s2y = 0;
  tetrad_definitions[tetrad_z].orientations[counter_clockwise].s3x = 0;
  tetrad_definitions[tetrad_z].orientations[counter_clockwise].s3y = 1;

  tetrad_definitions[tetrad_z].cx = 4;
  tetrad_definitions[tetrad_z].cy = 0;

  tetrad_definitions[tetrad_s].orientations[base].s1x = 1;
  tetrad_definitions[tetrad_s].orientations[base].s1y = 0;
  tetrad_definitions[tetrad_s].orientations[base].s2x = -1;
  tetrad_definitions[tetrad_s].orientations[base].s2y = 1;
  tetrad_definitions[tetrad_s].orientations[base].s3x = 0;
  tetrad_definitions[tetrad_s].orientations[base].s3y = 1;

  tetrad_definitions[tetrad_s].orientations[clockwise].s1x = 0;
  tetrad_definitions[tetrad_s].orientations[clockwise].s1y = -1;
  tetrad_definitions[tetrad_s].orientations[clockwise].s2x = 1;
  tetrad_definitions[tetrad_s].orientations[clockwise].s2y = 0;
  tetrad_definitions[tetrad_s].orientations[clockwise].s3x = 1;
  tetrad_definitions[tetrad_s].orientations[clockwise].s3y = 1;

  tetrad_definitions[tetrad_s].orientations[flipped].s1x = 1;
  tetrad_definitions[tetrad_s].orientations[flipped].s1y = 0;
  tetrad_definitions[tetrad_s].orientations[flipped].s2x = -1;
  tetrad_definitions[tetrad_s].orientations[flipped].s2y = 1;
  tetrad_definitions[tetrad_s].orientations[flipped].s3x = 0;
  tetrad_definitions[tetrad_s].orientations[flipped].s3y = 1;

  tetrad_definitions[tetrad_s].orientations[counter_clockwise].s1x = 0;
  tetrad_definitions[tetrad_s].orientations[counter_clockwise].s1y = -1;
  tetrad_definitions[tetrad_s].orientations[counter_clockwise].s2x = 1;
  tetrad_definitions[tetrad_s].orientations[counter_clockwise].s2y = 0;
  tetrad_definitions[tetrad_s].orientations[counter_clockwise].s3x = 1;
  tetrad_definitions[tetrad_s].orientations[counter_clockwise].s3y = 1;

  tetrad_definitions[tetrad_s].cx = 4;
  tetrad_definitions[tetrad_s].cy = 0;

  tetrad_definitions[tetrad_reverse_l].orientations[base].s1x = -1;
  tetrad_definitions[tetrad_reverse_l].orientations[base].s1y = 0;
  tetrad_definitions[tetrad_reverse_l].orientations[base].s2x = 1;
  tetrad_definitions[tetrad_reverse_l].orientations[base].s2y = 0;
  tetrad_definitions[tetrad_reverse_l].orientations[base].s3x = 1;
  tetrad_definitions[tetrad_reverse_l].orientations[base].s3y = 1;

  tetrad_definitions[tetrad_reverse_l].orientations[clockwise].s1x = 0;
  tetrad_definitions[tetrad_reverse_l].orientations[clockwise].s1y = -1;
  tetrad_definitions[tetrad_reverse_l].orientations[clockwise].s2x = 1;
  tetrad_definitions[tetrad_reverse_l].orientations[clockwise].s2y = -1;
  tetrad_definitions[tetrad_reverse_l].orientations[clockwise].s3x = 0;
  tetrad_definitions[tetrad_reverse_l].orientations[clockwise].s3y = 1;

  tetrad_definitions[tetrad_reverse_l].orientations[flipped].s1x = -1;
  tetrad_definitions[tetrad_reverse_l].orientations[flipped].s1y = -1;
  tetrad_definitions[tetrad_reverse_l].orientations[flipped].s2x = -1;
  tetrad_definitions[tetrad_reverse_l].orientations[flipped].s2y = 0;
  tetrad_definitions[tetrad_reverse_l].orientations[flipped].s3x = 1;
  tetrad_definitions[tetrad_reverse_l].orientations[flipped].s3y = 0;

  tetrad_definitions[tetrad_reverse_l].orientations[counter_clockwise].s1x = 0;
  tetrad_definitions[tetrad_reverse_l].orientations[counter_clockwise].s1y
    = -1;
  tetrad_definitions[tetrad_reverse_l].orientations[counter_clockwise].s2x
    = -1;
  tetrad_definitions[tetrad_reverse_l].orientations[counter_clockwise].s2y = 1;
  tetrad_definitions[tetrad_reverse_l].orientations[counter_clockwise].s3x = 0;
  tetrad_definitions[tetrad_reverse_l].orientations[counter_clockwise].s3y = 1;

  tetrad_definitions[tetrad_reverse_l].cx = 4;
  tetrad_definitions[tetrad_reverse_l].cy = 0;

  tetrad_definitions[tetrad_l].orientations[base].s1x = -1;
  tetrad_definitions[tetrad_l].orientations[base].s1y = 0;
  tetrad_definitions[tetrad_l].orientations[base].s2x = 1;
  tetrad_definitions[tetrad_l].orientations[base].s2y = 0;
  tetrad_definitions[tetrad_l].orientations[base].s3x = -1;
  tetrad_definitions[tetrad_l].orientations[base].s3y = 1;

  tetrad_definitions[tetrad_l].orientations[clockwise].s1x = 0;
  tetrad_definitions[tetrad_l].orientations[clockwise].s1y = -1;
  tetrad_definitions[tetrad_l].orientations[clockwise].s2x = 1;
  tetrad_definitions[tetrad_l].orientations[clockwise].s2y = 1;
  tetrad_definitions[tetrad_l].orientations[clockwise].s3x = 0;
  tetrad_definitions[tetrad_l].orientations[clockwise].s3y = 1;

  tetrad_definitions[tetrad_l].orientations[flipped].s1x = 1;
  tetrad_definitions[tetrad_l].orientations[flipped].s1y = -1;
  tetrad_definitions[tetrad_l].orientations[flipped].s2x = -1;
  tetrad_definitions[tetrad_l].orientations[flipped].s2y = 0;
  tetrad_definitions[tetrad_l].orientations[flipped].s3x = 1;
  tetrad_definitions[tetrad_l].orientations[flipped].s3y = 0;

  tetrad_definitions[tetrad_l].orientations[counter_clockwise].s1x = 0;
  tetrad_definitions[tetrad_l].orientations[counter_clockwise].s1y = -1;
  tetrad_definitions[tetrad_l].orientations[counter_clockwise].s2x = -1;
  tetrad_definitions[tetrad_l].orientations[counter_clockwise].s2y = -1;
  tetrad_definitions[tetrad_l].orientations[counter_clockwise].s3x = 0;
  tetrad_definitions[tetrad_l].orientations[counter_clockwise].s3y = 1;

  tetrad_definitions[tetrad_l].cx = 4;
  tetrad_definitions[tetrad_l].cy = 0; 

}
