/**
 * Implementation of the software paging unit.
 */
#include "addressTranslation.h"
#include <stdlib.h>

static pagetable *ptr = NULL; // ptr = "page table register"

void setPageTable(pagetable *pt) {
    ptr = pt;
}

int getPhysical(int logical) {

    int physicalAddress;

    // JD: You can avoid the hardcode by using certain #define's
    //     given in addressTranslation.h.
    if (logical > -1 && logical < 256) { // restrict to first 8 bits
        
        int page = (logical & PAGEMASK) >> PAGEBITS;
        // JD: You are right-shifting, so no need for that bitwise-&.
        if (page < PAGECOUNT) {
            // JD: ^^^^^Think about it...would this condition ever be true
            //     if the one on line 19 were also true?
            if (ptr[page].valid) {
                int frame = ptr[page].frame;
                int offset = (logical & PAGESIZE);
                physicalAddress = (frame << PAGEBITS) | offset;

            } else {
                physicalAddress = ERR_INVALID;
            }
            
        } else {
            physicalAddress = ERR_OUT_OF_RANGE;
        } 
        
    } else {
        physicalAddress = ERR_OUT_OF_RANGE;
    }

    return physicalAddress;

}
