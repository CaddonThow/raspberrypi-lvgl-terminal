#include "date.h"
#include <stdio.h>
#include <time.h>
#include "lvgl/lvgl.h"
#include "ui/src/ui.h"

const char* weekday[7] = {"Sun.", "Mon.", "Tue.", "Wed.", "Thu.", "Fri.", "Sat."};

void date_loop(void)
{
    time_t current_time;
    struct tm *time_info;
    char time_string[100];
    
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

    lv_label_set_text_fmt(ui_Time1Label, "%02d:%02d:%02d", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
    lv_label_set_text_fmt(ui_Time2Label, "%d-%02d-%02d %s", time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday, weekday[time_info->tm_wday]);
}