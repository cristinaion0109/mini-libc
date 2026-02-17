struct timespec {
    long tv_sec;
    long tv_nsec;
};

int nanosleep(struct timespec *t1, struct timespec *t2);
