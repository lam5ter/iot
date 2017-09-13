#ifndef IO_CONTROL_H
#define IO_CONTROL_H

typedef struct _flags {
    bool print;
    bool log;
} flags;

flags *update_flags(int num, char *args[]);
bool is_log(flags *f);
void record_data(flags *f, char *weather, int colour);
void init_io();
void update_rgb(int colour);
bool is_exit();
void reset_rgb();
void reset_gpio();

#endif
