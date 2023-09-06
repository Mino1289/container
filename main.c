#include <getopt.h>
#include <string.h>

#include <container.h>
#include <deck.h>
#include <literater.h>

typedef struct config {
    bool verbose;
    char input[STR_MAX_LEN];
    char output[STR_MAX_LEN];
} config;

int main(int argc, char* argv[]) {
    config cfg = {
        .verbose = false,
        .input = "",
        .output = "",
    };

    struct option my_opts[] = {
        {.name = "verbose", .has_arg = 0, .flag = 0, .val = 'v'},
        {.name = "input", .has_arg = 1, .flag = 0, .val = 'i'},
        {.name = "output", .has_arg = 1, .flag = 0, .val = 'o'},
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "vi:o:", my_opts, NULL)) != EOF) {
        switch (opt) {
            case 'v':
                cfg.verbose = true;
                break;
            
            case 'i':
                strncpy(cfg.input, optarg, STR_MAX_LEN);
                break;

            case 'o':
                strncpy(cfg.output, optarg, STR_MAX_LEN);
                break;
        }
    }
    printf("Config:\n\tVerbose: %s\n\tInput: %s\n\tOutput: %s\n", cfg.verbose ? "yes": "no", cfg.input, cfg.output);

    const char filename[] = "test.txt";
    FILE* f = fopen(filename, "r");


    Deck deck;
    int n_dest, n_ctn;
    int* dest = NULL;
    Container* ctn = NULL;
    read_f(f, &deck, &n_dest, &n_ctn, &dest, &ctn);
    print_Deck(deck);
    
    for (int i = 0; i < n_dest; i++) {
        printf("%d ", dest[i]);
    }
    printf("\n");
    for (int i = 0; i < n_ctn; i++) {
        print_Container(ctn[i]);
    }

    fclose(f);
    free(dest);
    free(ctn);
    free_Deck(&deck);

    return 0;
}