#include "College.h"

int main() {
    // Create an object then use debug tool to check it works
    College MU;
    MU.showRanking();

    College UF("The University of Florida", 7);
    College FSU("Florida State University", 23);
    UF.showRanking();
    FSU.showRanking();

};