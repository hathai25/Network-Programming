#include <stdio.h>
#include <stdlib.h>

int main() {
    // Execute ifconfig command
    system("ifconfig > ifconfig_output.txt");

    // Write ifconfig output to HTML file
    FILE *ifconfig_file = fopen("ifconfig_output.txt", "r");
    FILE *ifconfig_html = fopen("ifconfig_output.html", "w");
    if (ifconfig_html != NULL && ifconfig_file != NULL) {
        fprintf(ifconfig_html, "<div>\n");
        fprintf(ifconfig_html, "<pre>\n");
        char buffer[256];
        while (fgets(buffer, 256, ifconfig_file) != NULL) {
            fprintf(ifconfig_html, "%s", buffer);
        }
        fprintf(ifconfig_html, "</pre>\n");
        fprintf(ifconfig_html, "</div>\n");
        fclose(ifconfig_html);
        fclose(ifconfig_file);
    }

    // Execute ls command
    system("ls -a -l > ls_output.txt");

    // Write ls output to HTML file
    FILE *ls_file = fopen("ls_output.txt", "r");
    FILE *ls_html = fopen("ls_output.html", "w");
    if (ls_html != NULL && ls_file != NULL) {
        fprintf(ls_html, "<div>\n");
        fprintf(ls_html, "<pre>\n");
        char buffer[256];
        while (fgets(buffer, 256, ls_file) != NULL) {
            fprintf(ls_html, "%s", buffer);
        }
        fprintf(ls_html, "</pre>\n");
        fprintf(ls_html, "</div>\n");
        fclose(ls_html);
        fclose(ls_file);
    }

    return 0;
}
