#include "log.h"
#include "access.h"
int main(int argc, char **argv){
    char PROCESS_NAME[64] = "myprocessname";
    log_init_file("./", PROCESS_NAME, LOG_LEVEL_DBG, 300 * 1024 * 1024);
    char accesspath[PATH_MAX];
    accesspath[PATH_MAX - 1] = 0;
    snprintf(accesspath, PATH_MAX - 1, "%s_access", PROCESS_NAME);
    access_init_file("./", accesspath, 300 * 1024 * 1024);

    snprintf(g_log_ctx.prefix_tags, sizeof(g_log_ctx.prefix_tags) - 1,"%s:%hu\tLOG\t%s",
            "0.0.0.0", (unsigned short)(8935), PROCESS_NAME);
    snprintf(g_conf_access.prefix_tags, sizeof(g_conf_access.prefix_tags) - 1,"%s:%hu\tACCESS\t%s",
            "0.0.0.0", (unsigned short)(8935), PROCESS_NAME);

    //log_set_level(LOG_LEVEL_INF);
    //log_set_max_size(300 * 1024 * 1024);
    //access_set_max_size(300 * 1024 * 1024);
    fprintf(stderr, "start!\n");
    INF("start !!!");

    return 0;
}
