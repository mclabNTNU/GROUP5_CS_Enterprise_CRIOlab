/*
 * ctrl_student_HIL_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.170
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Apr 24 10:44:57 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_student_HIL_types_h_
#define RTW_HEADER_ctrl_student_HIL_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#ifndef _DEFINED_TYPEDEF_FOR_struct_O2L20z72exSZsAYx6iSa3F_
#define _DEFINED_TYPEDEF_FOR_struct_O2L20z72exSZsAYx6iSa3F_

typedef struct {
  real_T origin[2];
  real_T threshold;
  real_T scale;
  real_T x_max_limit;
  real_T x_min_limit;
  real_T y_min_limit;
  real_T y_max_limit;
  real_T x_min;
  real_T x_max;
  real_T y_min;
  real_T y_max;
} struct_O2L20z72exSZsAYx6iSa3F;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_FIFD4OBMD9VWlACOsEb4SC_
#define _DEFINED_TYPEDEF_FOR_struct_FIFD4OBMD9VWlACOsEb4SC_

typedef struct {
  real_T Enable;
  real_T power;
  real_T Sample_freq;
} struct_FIFD4OBMD9VWlACOsEb4SC;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_UqjEawrvuS8Txm2V5QOEXC_
#define _DEFINED_TYPEDEF_FOR_struct_UqjEawrvuS8Txm2V5QOEXC_

typedef struct {
  real_T Enable;
  real_T length;
  real_T threshold;
  real_T Power;
} struct_UqjEawrvuS8Txm2V5QOEXC;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_m5RSTwsTQK5soBPAz6vCR_
#define _DEFINED_TYPEDEF_FOR_struct_m5RSTwsTQK5soBPAz6vCR_

typedef struct {
  real_T M_inv[9];
  real_T L_1[9];
  real_T L_2[9];
  real_T L_3[9];
  real_T x_0[9];
} struct_m5RSTwsTQK5soBPAz6vCR;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_yOlW1NNwA91Ojwjtwi6OcE_
#define _DEFINED_TYPEDEF_FOR_struct_yOlW1NNwA91Ojwjtwi6OcE_

typedef struct {
  real_T Eta_0[3];
} struct_yOlW1NNwA91Ojwjtwi6OcE;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_dG7PRX1V63dlz6vAPmePvC_
#define _DEFINED_TYPEDEF_FOR_struct_dG7PRX1V63dlz6vAPmePvC_

typedef struct {
  real_T mu;
  real_T U_ref;
  real_T U_ref_dot;
  real_T s_0;
  real_T eta_d_0[3];
  real_T eta_d_1[3];
  real_T K_p[9];
  real_T c_2;
  real_T M[9];
  real_T Ellipsoid;
  real_T r[2];
  real_T c[2];
  real_T constant_heading;
  real_T heading;
} struct_dG7PRX1V63dlz6vAPmePvC;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_ugpof3UgEA54frSa7owjeE_
#define _DEFINED_TYPEDEF_FOR_struct_ugpof3UgEA54frSa7owjeE_

typedef struct {
  struct_O2L20z72exSZsAYx6iSa3F Workspace;
  struct_FIFD4OBMD9VWlACOsEb4SC Noise;
  struct_UqjEawrvuS8Txm2V5QOEXC Freeze;
  real_T Sample_time;
  real_T Thrust_lim[3];
  struct_m5RSTwsTQK5soBPAz6vCR Observer;
  struct_yOlW1NNwA91Ojwjtwi6OcE Model;
  struct_dG7PRX1V63dlz6vAPmePvC Guidance;
} struct_ugpof3UgEA54frSa7owjeE;

#endif

/* Parameters (auto storage) */
typedef struct P_ctrl_student_HIL_T_ P_ctrl_student_HIL_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ctrl_student_HIL_T RT_MODEL_ctrl_student_HIL_T;

#endif                                 /* RTW_HEADER_ctrl_student_HIL_types_h_ */
