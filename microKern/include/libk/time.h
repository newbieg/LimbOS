#ifndef KERNEL_TIME_H
#define KERNEL_TIME_H


struct time_t {
		unsigned int second;
		unsigned int minute;
		unsigned int hour;
		unsigned int day;
		unsigned int month;
		unsigned int year;
};

#endif
