/*
 * ctrl_student_HIL_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student_HIL".
 *
 * Model version              : 1.171
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Feb 21 14:30:27 2017
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

#ifndef _DEFINED_TYPEDEF_FOR_struct_F5jpQk0SqNXWbjvSxP6eo_
#define _DEFINED_TYPEDEF_FOR_struct_F5jpQk0SqNXWbjvSxP6eo_

typedef struct {
  real_T Power;
} struct_F5jpQk0SqNXWbjvSxP6eo;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_iTdVtkn32GXKLcWyghsjmG_
#define _DEFINED_TYPEDEF_FOR_struct_iTdVtkn32GXKLcWyghsjmG_

typedef struct {
  real_T c_u;
  real_T c_v;
  real_T c_psi;
} struct_iTdVtkn32GXKLcWyghsjmG;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_O1cG5VeM3Vq2W5nll3MmiD_
#define _DEFINED_TYPEDEF_FOR_struct_O1cG5VeM3Vq2W5nll3MmiD_

typedef struct {
  struct_iTdVtkn32GXKLcWyghsjmG omega;
} struct_O1cG5VeM3Vq2W5nll3MmiD;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_DWUTGWKNBPtk9cG3B8wRwC_
#define _DEFINED_TYPEDEF_FOR_struct_DWUTGWKNBPtk9cG3B8wRwC_

typedef struct {
  real_T M_inv[9];
  real_T x_hat_0[9];
} struct_DWUTGWKNBPtk9cG3B8wRwC;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_Tua5AtG6X91aH63nvtg47G_
#define _DEFINED_TYPEDEF_FOR_struct_Tua5AtG6X91aH63nvtg47G_

typedef struct {
  real_T K_psi_init;
  struct_CEDELhVBNVS20OOZKu6U0B Workspace;
  real_T SensNoiseEnabled;
  struct_WEndDd5z8WjUYRTCKDNizF Freeze;
  real_T Step_size;
  real_T Sample_time;
  real_T Sample_rate;
  struct_F5jpQk0SqNXWbjvSxP6eo Noise;
  real_T Thrust_lim[3];
  struct_O1cG5VeM3Vq2W5nll3MmiD Lowpass;
  struct_DWUTGWKNBPtk9cG3B8wRwC Observer;
} struct_Tua5AtG6X91aH63nvtg47G;

#endif

/* Parameters (auto storage) */
typedef struct P_ctrl_student_HIL_T_ P_ctrl_student_HIL_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ctrl_student_HIL_T RT_MODEL_ctrl_student_HIL_T;

#endif                                 /* RTW_HEADER_ctrl_student_HIL_types_h_ */
