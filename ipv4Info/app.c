#include <stdio.h>
#include <stdint.h>

size_t readLine(char *result, const size_t maxLength){
    char c = getchar();
    size_t i = 0;
    while(c != '\n' && i < maxLength - 1){
        result[i++] = c;
        c = getchar();
    }
    result[i] = '\0';
    return i;
}

int8_t checkIpAddressString(char *string, const size_t length){
    size_t i, j, dots = 0;
    for(i = 0;i < length;i++){
        if((string[i] < '0' || string[i] > '9') && string[i] != '.'){
            for(j = i;j < length - 1;j++){
                string[j] = string[j + 1];
            }
        }else if(string[i] == '.'){
            dots++;
        }
    }
    if(dots != 3){
        printf("ERROR: invalid ip adres!\n");
        return -1;
    }
    return 0;
}

int8_t getAdres(uint8_t *ipAddress, const char *string){
    uint32_t octets[4];
    sscanf(string, "%u . %u . %u . %u", octets, octets + 1, octets + 2, octets + 3);
    for(size_t i = 0;i < 4;i++){
        if(octets[i] > 255){
            printf("ERROR: Invalid octet!\n");
            return -1;
        }
        ipAddress[i] = octets[i];
    }
    return 0;
}

int8_t getIpAdres(uint8_t *ipAdres){
    char string[100];
    size_t length = readLine(string, 100);
    if(checkIpAddressString(string, length) == -1){
        return -1;
    }else if(getAdres(ipAdres, string) == -1){
        return -2;
    }
    return 0;
}

int8_t getMacAdres(uint8_t *macAdres){
    int8_t result = getIpAdres(macAdres);
    size_t i, j;
    uint8_t octet;
    if(result < 0){
        return result;
    }
    for(i = 0;i < 4;i++){
        octet = macAdres[i];
        if(macAdres[i] != 255){
            for(j = i + 1;j < 4;j++){
                if(macAdres[j] != 0){
                    printf("ERROR: Invalid MAC-adres!\n");
                    return -3;
                }
            }
        }else if(octet != 255 && octet != 254 && octet != 252 && octet != 248 && octet != 240 && octet != 224 && octet != 192 && octet != 128){
            printf("ERROR: Invalid MAC-adres octet!\n");
            return -4;
        }
    }
    return 0;
}

uint32_t ipArrayToUint(uint8_t *adres){
    uint32_t result = adres[0];
    for(uint8_t i = 1;i < 4;i++){
        result = (result << 8) | adres[i];
    }
    return result;
}

uint8_t getIpType(uint32_t ip, uint32_t mac){
    if((ip & ~mac) == 0){
        return 0;
    }else if((ip & ~mac) == (~mac)){
        return 1;
    }else{
        return 2;
    }
}

int main(){
    uint8_t ipAdres[4];
    uint8_t macAdres[4];
    uint8_t type;
    while(1){
        printf("Enter an IP-adres: ");
        if(getIpAdres(ipAdres) < 0){
            continue;
        }
        printf("Enter a MAC-adres: ");
        if(getMacAdres(macAdres) < 0){
            continue;
        }
        printf("%u.%u.%u.%u\n", ipAdres[0], ipAdres[1], ipAdres[2], ipAdres[3]);
        printf("%u.%u.%u.%u\n", macAdres[0], macAdres[1], macAdres[2], macAdres[3]);
        type = getIpType(ipArrayToUint(ipAdres), ipArrayToUint(macAdres));
        switch(type){
            case 0:
                puts("It is a network adres.\n");
                break;
            case 1:
                puts("It is a broadcast adres.\n");
                break;
            case 2:
                puts("It is a host adres.\n");
                break;
            default:
                puts("Something went wrong...\n");
        }
    }
}
