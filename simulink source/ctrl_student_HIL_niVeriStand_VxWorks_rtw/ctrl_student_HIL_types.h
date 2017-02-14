/*
 * ctrl_student_HIL_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.119
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Feb 14 14:11:45 2017
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
#ifndef _DEFINED_TYPEDEF_FOR_struct_WEndDd5z8WjUYRTCKDNizF_
#define _DEFINED_TYPEDEF_FOR_struct_WEndDd5z8WjUYRTCKDNizF_

typedef struct {
  real_T Enable;
  real_T length;
  real_T threshold;
} struct_WEndDd5z8WjUYRTCKDNizF;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_7nWQhuobG7WuDbLiQPONjG_
#define _DEFINED_TYPEDEF_FOR_struct_7nWQhuobG7WuDbLiQPONjG_

typedef struct {
  real_T SensNoiseEnabled;
  struct_WEndDd5z8WjUYRTCKDNizF Freeze;
  real_T Step_size;
  real_T Sample_time;
  real_T Thrust_lim[3];
} struct_7nWQhuobG7WuDbLiQPONjG;

#endif

/* Parameters (auto storage) */
typedef struct P_ctrl_student_HIL_T_ P_ctrl_student_HIL_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ctrl_student_HIL_T RT_MODEL_ctrl_student_HIL_T;

#endif                                 /* RTW_HEADER_ctrl_student_HIL_types_h_ */
