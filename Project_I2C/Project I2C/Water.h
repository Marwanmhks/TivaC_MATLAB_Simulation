/*
 * File: Water.h
 *
 * Code generated for Simulink model 'Water'.
 *
 * Model version                  : 1.88
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Tue May 26 16:02:32 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->Stellaris Cortex-M3
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Water_h_
#define RTW_HEADER_Water_h_
#include <stddef.h>
#include <math.h>
#ifndef Water_COMMON_INCLUDES_
# define Water_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Water_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S3>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE;            /* '<S33>/Integrator' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Water_initialize(void);
extern void Water_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('watertank/Water ')    - opens subsystem watertank/Water
 * hilite_system('watertank/Water /Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'watertank'
 * '<S1>'   : 'watertank/Water '
 * '<S2>'   : 'watertank/Water /PID Controller'
 * '<S3>'   : 'watertank/Water /Water-Tank System'
 * '<S4>'   : 'watertank/Water /PID Controller/Anti-windup'
 * '<S5>'   : 'watertank/Water /PID Controller/D Gain'
 * '<S6>'   : 'watertank/Water /PID Controller/Filter'
 * '<S7>'   : 'watertank/Water /PID Controller/Filter ICs'
 * '<S8>'   : 'watertank/Water /PID Controller/I Gain'
 * '<S9>'   : 'watertank/Water /PID Controller/Ideal P Gain'
 * '<S10>'  : 'watertank/Water /PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'watertank/Water /PID Controller/Integrator'
 * '<S12>'  : 'watertank/Water /PID Controller/Integrator ICs'
 * '<S13>'  : 'watertank/Water /PID Controller/N Copy'
 * '<S14>'  : 'watertank/Water /PID Controller/N Gain'
 * '<S15>'  : 'watertank/Water /PID Controller/P Copy'
 * '<S16>'  : 'watertank/Water /PID Controller/Parallel P Gain'
 * '<S17>'  : 'watertank/Water /PID Controller/Reset Signal'
 * '<S18>'  : 'watertank/Water /PID Controller/Saturation'
 * '<S19>'  : 'watertank/Water /PID Controller/Saturation Fdbk'
 * '<S20>'  : 'watertank/Water /PID Controller/Sum'
 * '<S21>'  : 'watertank/Water /PID Controller/Sum Fdbk'
 * '<S22>'  : 'watertank/Water /PID Controller/Tracking Mode'
 * '<S23>'  : 'watertank/Water /PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'watertank/Water /PID Controller/postSat Signal'
 * '<S25>'  : 'watertank/Water /PID Controller/preSat Signal'
 * '<S26>'  : 'watertank/Water /PID Controller/Anti-windup/Passthrough'
 * '<S27>'  : 'watertank/Water /PID Controller/D Gain/Disabled'
 * '<S28>'  : 'watertank/Water /PID Controller/Filter/Disabled'
 * '<S29>'  : 'watertank/Water /PID Controller/Filter ICs/Disabled'
 * '<S30>'  : 'watertank/Water /PID Controller/I Gain/Internal Parameters'
 * '<S31>'  : 'watertank/Water /PID Controller/Ideal P Gain/Passthrough'
 * '<S32>'  : 'watertank/Water /PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S33>'  : 'watertank/Water /PID Controller/Integrator/Discrete'
 * '<S34>'  : 'watertank/Water /PID Controller/Integrator ICs/Internal IC'
 * '<S35>'  : 'watertank/Water /PID Controller/N Copy/Disabled wSignal Specification'
 * '<S36>'  : 'watertank/Water /PID Controller/N Gain/Disabled'
 * '<S37>'  : 'watertank/Water /PID Controller/P Copy/Disabled'
 * '<S38>'  : 'watertank/Water /PID Controller/Parallel P Gain/Internal Parameters'
 * '<S39>'  : 'watertank/Water /PID Controller/Reset Signal/Disabled'
 * '<S40>'  : 'watertank/Water /PID Controller/Saturation/Passthrough'
 * '<S41>'  : 'watertank/Water /PID Controller/Saturation Fdbk/Disabled'
 * '<S42>'  : 'watertank/Water /PID Controller/Sum/Sum_PI'
 * '<S43>'  : 'watertank/Water /PID Controller/Sum Fdbk/Disabled'
 * '<S44>'  : 'watertank/Water /PID Controller/Tracking Mode/Disabled'
 * '<S45>'  : 'watertank/Water /PID Controller/Tracking Mode Sum/Passthrough'
 * '<S46>'  : 'watertank/Water /PID Controller/postSat Signal/Forward_Path'
 * '<S47>'  : 'watertank/Water /PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_Water_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
