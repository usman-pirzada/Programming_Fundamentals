#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definitions
struct WeatherForecast {
    float temperature;
    float rainfall;
    float wind_speed;
};

struct Crop {
    char crop_type[50];
    int growth_stage;
    float expected_yield;
    struct WeatherForecast* weather_forecast;
};

struct Field {
    float gps_latitude;
    float gps_longitude;
    float soil_health;
    float moisture_level;
    struct Crop* crops;
    int crop_count;
};

struct RegionalHub {
    struct Field* fields;
    int field_count;
};

struct CentralServer {
    struct RegionalHub** hubs;
    int hub_count;
};

// Function prototypes
struct WeatherForecast* create_weather_forecast(float temperature, float rainfall, float wind_speed);
struct Crop* create_crop(const char* crop_type, int growth_stage, float expected_yield, struct WeatherForecast* forecast);
struct Field* create_field(float latitude, float longitude, float soil_health, float moisture_level, int crop_count);
struct RegionalHub* create_hub(int field_count);
void connect_hubs_to_server(struct CentralServer* server, struct RegionalHub** hubs, int hub_count);
void cleanup(struct CentralServer* server);
void displayData(struct CentralServer* server);

int main() {
    // Initialize central server
    struct CentralServer central_server = { .hub_count = 0, .hubs = NULL };
    // Create weather forecast
    struct WeatherForecast* wf = create_weather_forecast(25.5, 10.2, 5.0);
    // Create crops
    struct Crop* crop = create_crop("Wheat", 2, 150.0, wf);
    // Create a field and assign crops
    struct Field* field = create_field(25.0, 71.5, 85.0, 60.0, 1);
    field->crops[0] = *crop;
    // Create a regional hub and assign fields
    struct RegionalHub* hub = create_hub(1);
    hub->fields[0] = *field;
    // Add hub to central server
    struct RegionalHub* hubs[] = { hub };
    connect_hubs_to_server(&central_server, hubs, 1);
    printf("System initialized with %d hub(s).\n", central_server.hub_count);

    // Display the stored data
    displayData(&central_server);

    // Cleanup allocated memory
    cleanup(&central_server);
    return 0;
}

// Function implementations
struct WeatherForecast* create_weather_forecast(float temperature, float rainfall, float wind_speed) {
    struct WeatherForecast* wf = (struct WeatherForecast*)malloc(sizeof(struct WeatherForecast));
    wf->temperature = temperature;
    wf->rainfall = rainfall;
    wf->wind_speed = wind_speed;
    return wf;
}

struct Crop* create_crop(const char* crop_type, int growth_stage, float expected_yield, struct WeatherForecast* forecast) {
    struct Crop* crop = (struct Crop*)malloc(sizeof(struct Crop));
    strcpy(crop->crop_type, crop_type);
    crop->growth_stage = growth_stage;
    crop->expected_yield = expected_yield;
    crop->weather_forecast = forecast;
    return crop;
}

struct Field* create_field(float latitude, float longitude, float soil_health, float moisture_level, int crop_count) {
    struct Field* field = (struct Field*)malloc(sizeof(struct Field));
    field->gps_latitude = latitude;
    field->gps_longitude = longitude;
    field->soil_health = soil_health;
    field->moisture_level = moisture_level;
    field->crop_count = crop_count;
    field->crops = (struct Crop*)malloc(sizeof(struct Crop) * crop_count);
    return field;
}

struct RegionalHub* create_hub(int field_count) {
    struct RegionalHub* hub = (struct RegionalHub*)malloc(sizeof(struct RegionalHub));
    hub->field_count = field_count;
    hub->fields = (struct Field*)malloc(sizeof(struct Field) * field_count);
    return hub;
}

void connect_hubs_to_server(struct CentralServer* server, struct RegionalHub** hubs, int hub_count) {
    server->hub_count = hub_count;
    server->hubs = (struct RegionalHub**)malloc(sizeof(struct RegionalHub*) * hub_count);
    for (int i = 0; i < hub_count; i++) {
        server->hubs[i] = hubs[i];
    }
}

void displayData(struct CentralServer* server) {
    for (int i = 0; i < server->hub_count; i++) {
        struct RegionalHub* hub = server->hubs[i];
        printf("Hub %d:\n", i + 1);
        for (int j = 0; j < hub->field_count; j++) {
            struct Field* field = &hub->fields[j];
            printf("\tField %d:\n", j + 1);
            printf("\t\tGPS Latitude: %.2f\n", field->gps_latitude);
            printf("\t\tGPS Longitude: %.2f\n", field->gps_longitude);
            printf("\t\tSoil Health: %.2f\n", field->soil_health);
            printf("\t\tMoisture Level: %.2f\n", field->moisture_level);
            for (int k = 0; k < field->crop_count; k++) {
                struct Crop* crop = &field->crops[k];
                printf("\t\tCrop %d:\n", k + 1);
                printf("\t\t\tType: %s\n", crop->crop_type);
                printf("\t\t\tGrowth Stage: %d\n", crop->growth_stage);
                printf("\t\t\tExpected Yield: %.2f\n", crop->expected_yield);
                struct WeatherForecast* wf = crop->weather_forecast;
                printf("\t\t\tWeather Forecast:\n");
                printf("\t\t\t\tTemperature: %.2f\n", wf->temperature);
                printf("\t\t\t\tRainfall: %.2f\n", wf->rainfall);
                printf("\t\t\t\tWind Speed: %.2f\n", wf->wind_speed);
            }
        }
    }
}

void cleanup(struct CentralServer* server) {
    for (int i = 0; i < server->hub_count; i++) {
        struct RegionalHub* hub = server->hubs[i];
        for (int j = 0; j < hub->field_count; j++) {
            struct Field* field = &hub->fields[j];
            free(field->crops);
        }
        free(hub->fields);
        free(hub);
    }
    free(server->hubs);
}