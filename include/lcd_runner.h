#ifndef LCD_RUNNER_H
#define LCD_RUNNER_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================
 *  Public Function Prototypes
 *============================================================*/

/**
 * @brief LCD task handler
 *
 * This function is intended to be called periodically
 * (e.g., from an RTOS task or main loop) to update
 * and manage LCD display content.
 */
int task_power_lcd(int argc, char *argv[]);

void set_lcd_power( int power );

#ifdef __cplusplus
}
#endif

#endif /* LCD_RUNNER_H */
