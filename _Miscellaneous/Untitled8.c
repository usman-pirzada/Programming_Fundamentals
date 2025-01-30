#include <stdio.h>
#include <stdlib.h>

struct Content_Based {
    int eng_Matrix;
} **contentBased;

struct deviceBased {
    char *resolutionPrefs[20];
    char *historyPlayback[20];
    char *bandwidthHistory[20];
} **deviceMatrix;

int main() {
    // Declare variables
    int maxUsers = 3, maxDevices = 2, maxCategories = 3;
    int maxBandwidth, maxPlayback, maxResolution;
    
//    struct ContentBased** contentBased;
//    struct DeviceMetric** deviceMatrix;
//    int* resolutionPrefs;
//    int* historyPlayback;
//    int* bandwidthHistory;

    // Allocate memory for contentBased
    contentBased = (struct Content_Based**)malloc(maxUsers * sizeof(struct Content_Based*));
    if (contentBased == NULL) {
        fprintf(stderr, "Memory allocation failed for contentBased\n");
        return 1; // Exit with error
    }
    for (int i = 0; i < maxUsers; i++) {
        contentBased[i] = (struct Content_Based*)malloc(maxCategories * sizeof(struct Content_Based));
        if (contentBased[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for contentBased[%d]\n", i);
            return 1; // Exit with error
        }
    }

    // Allocate memory for deviceMatrix
    deviceMatrix = (struct deviceBased**)malloc(maxUsers * sizeof(struct deviceBased*));
    if (deviceMatrix == NULL) {
        fprintf(stderr, "Memory allocation failed for deviceMatrix\n");
        return 1; // Exit with error
    }
    for (int i = 0; i < maxUsers; i++) {
        deviceMatrix[i] = (struct deviceBased*)malloc(maxDevices * sizeof(struct deviceBased));
        if (deviceMatrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for deviceMatrix[%d]\n", i);
            return 1; // Exit with error
        }
    }

    // Allocate memory for resolutionPrefs
    resolutionPrefs = (int*)malloc(maxResolution * sizeof(int));
    if (resolutionPrefs == NULL) {
        fprintf(stderr, "Memory allocation failed for resolutionPrefs\n");
        return 1; // Exit with error
    }

        // Allocate memory for historyPlayback
    historyPlayback = (int*)malloc(maxPlayback * sizeof(int));
    if (historyPlayback == NULL) {
        fprintf(stderr, "Memory allocation failed for historyPlayback\n");
        return 1; // Exit with error
    }

    // Allocate memory for bandwidthHistory
    bandwidthHistory = (int*)malloc(maxBandwidth * sizeof(int));
    if (bandwidthHistory == NULL) {
        fprintf(stderr, "Memory allocation failed for bandwidthHistory\n");
        return 1; // Exit with error
    }

    // Example of initializing the structures (you can modify as needed)
    for (int i = 0; i < maxUsers; i++) {
        for (int j = 0; j < maxCategories; j++) {
            // Initialize contentBased[i][j] as needed
        }
        for (int j = 0; j < maxDevices; j++) {
            // Initialize deviceMatrix[i][j] as needed
        }
    }

    // Example of using the allocated arrays
    for (int i = 0; i < maxResolution; i++) {
        resolutionPrefs[i] = 0; // Initialize resolution preferences
    }

    for (int i = 0; i < maxPlayback; i++) {
        historyPlayback[i] = 0; // Initialize playback history
    }

    for (int i = 0; i < maxBandwidths; i++) {
        bandwidthHistory[i] = 0; // Initialize bandwidth history
    }

    // Free allocated memory
    for (int i = 0; i < maxUsers; i++) {
        free(contentBased[i]);
        free(deviceMatrix[i]);
    }
    free(contentBased);
    free(deviceMatrix);
    free(resolutionPrefs);
    free(historyPlayback);
    free(bandwidthHistory);

    return 0; // Exit successfully
}