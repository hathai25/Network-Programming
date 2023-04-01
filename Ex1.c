#include<stdio.h>
#include <stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/dir.h>
#include<malloc.h>

int main() {
   //Pham Huy Ha Thai - 20204784
    printf("Ifconfig below:\n");
    system("ifconfig");
    printf("ls -a -l below:\n");
    system("ls -a -l");

    printf("\nNow check the html file in the same directory\n");
    struct dirent **entries;
    int num_entries, i;

    DIR *dir = opendir("../");
    if (dir == NULL) {
        perror("opendir");
    }

    num_entries = scandir(".", &entries, NULL, alphasort);
    if (num_entries < 0) {
        perror("scandir");
    }

    FILE *outfile = fopen("output.html", "w");
    if (outfile == NULL) {
        perror("fopen");
    }

    fprintf(outfile, "<html>\n<body>\n");

    for (i = 0; i < num_entries; i++) {
        if(entries[i]->d_type == DT_DIR){
            fprintf(outfile, "<a href=\"%s\"><b>%s</b></a><br>\n", entries[i]->d_name, entries[i]->d_name);
        } else {
            fprintf(outfile, "<a href=\"%s\"><i>%s</i></a><br>\n", entries[i]->d_name, entries[i]->d_name);
        }
        free(entries[i]);
    }

    fprintf(outfile, "</body>\n</html>\n");
    free(entries);

    fclose(outfile);

    closedir(dir);

    return 0;
}
