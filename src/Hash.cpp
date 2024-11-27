//
// Created by Saanj Patel on 11/22/2024.
//

#include "Hash.h"

void HashMap::addPass(string& password) {
    passMap[password]++;

}

bool HashMap::checkPass(string &password) {
    return passMap.find(password) == passMap.end(); // not in the map, so it's unique
}
