# System Programming Lab 11 Multiprocessing

## My implementation
I made a new C file called movie.c that creates 50 frames. It takes in a parameter -c to
determine the number of processes to use, and more processes greatly reduces total load time.
Each process runs the program mandel.c to create a frame, slightly adjusting the parameter to gradually zoom in frame by frame.
Each of the 50 frames has a number between 0 and 49 at the end of its filename to order them.

## Excel Plot
https://github.com/MSOE-CPE2600/multiprocessing-turney-comiton/blob/main/Excel_plot.jpg

## Results
The plot shows a noticeable performance boost as the number of processes increases, at least until it hits around ten. When 20 is run,
the performance is not better than that of 10, but rather 2 seconds longer. This makes sense that it stops getting faster around 10, because the laptop that it was tested on has 12 cores, with other programs open in the background.
