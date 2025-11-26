/*
 * Filename: movie.c
 * Author: Nicholas Comito
 * Date: 11/18/2025
 * Purpose: Uses multiprocessing to create 50 frames
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int children = 4;
    char *xstr = "0", *ystr = "0", *tstr = "1";
    double start_scale = 0.05; 
    int frames = 50;

    int opt;
    while((opt = getopt(argc, argv, "x:y:t:c:s:")) != -1) {
        switch(opt) {
            case 'x': xstr = optarg; break;
            case 'y': ystr = optarg; break;
            case 't': tstr = optarg; break;
            case 'c': children = atoi(optarg); break;
            case 's': start_scale = atof(optarg); break;
        }
    }

    int active = 0;
    for(int f=0; f<frames; f++) {
        while(active >= children) { wait(NULL); active--; }

        pid_t pid = fork();
        if(pid == 0) {
            // child process
            double scale = start_scale * (1.0 - 0.98 * f/(frames-1));
            char sarg[32], filename[32];
            snprintf(sarg, sizeof(sarg), "%lf", scale);
            snprintf(filename, sizeof(filename), "mandel%03d.jpg", f);

            execl("./mandel", "mandel",
                  "-x", xstr,
                  "-y", ystr,
                  "-s", sarg,
                  "-t", tstr,
                  "-W", "1000",
                  "-H", "1000",
                  "-m", "2000",
                  "-o", filename,
                  NULL);
            perror("execl failed");
            exit(1);
        }
        active++;
    }

    while(wait(NULL) > 0);
    printf("All frames done.\n");
    return 0;
}