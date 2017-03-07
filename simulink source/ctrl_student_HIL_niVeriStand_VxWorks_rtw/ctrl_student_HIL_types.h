/*
 * ctrl_student_HIL_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.179
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Mar 07 15:44:08 2017
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
#ifndef _DEFINED_TYPEDEF_FOR_struct_CEDELhVBNVS20OOZKu6U0B_
#define _DEFINED_TYPEDEF_FOR_struct_CEDELhVBNVS20OOZKu6U0B_

typedef struct {
  real_T origin[2];
  real_T threshold;
  real_T gain;
  real_T x_max_limit;
  real_T x_min_limit;
  real_T y_max_limit;
  real_T y_min_limit;
  real_T x_min;
  real_T x_max;
  real_T y_min;
  real_T y_max;
} struct_CEDELhVBNVS20OOZKu6U0B;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_WEndDd5z8WjUYRTCKDNizF_
#define _DEFINED_TYPEDEF_FOR_struct_WEndDd5z8WjUYRTCKDNizF_

typedef struct {
  real_T Enable;
  real_T length;
  real_T threshold;
} struct_WEndDd5z8WjUYRTCKDNizF;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_DWUTGWKNBPtk9cG3B8wRwC_
#define _DEFINED_TYPEDEF_FOR_struct_DWUTGWKNBPtk9cG3B8wRwC_

typedef struct {
  real_T M_inv[9];
  real_T x_hat_0[9];
} struct_DWUTGWKNBPtk9cG3B8wRwC;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_FSsBvEVK8AhCsBqw22fikF_
#define _DEFINED_TYPEDEF_FOR_struct_FSsBvEVK8AhCsBqw22fikF_

typedef struct {
  real_T K_psi_init;
  struct_CEDELhVBNVS20OOZKu6U0B Workspace;
  struct_WEndDd5z8WjUYRTCKDNizF Freeze;
  real_T Sample_freq;
  real_T Thrust_lim[3];
  struct_DWUTGWKNBPtk9cG3B8wRwC Observer;
} struct_FSsBvEVK8AhCsBqw22fikF;

#endif

/* Parameters (auto storage) */
typedef struct P_ctrl_student_HIL_T_ P_ctrl_student_HIL_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ctrl_student_HIL_T RT_MODEL_ctrl_student_HIL_T;

#endif                                 /* RTW_HEADER_ctrl_student_HIL_types_h_ */
