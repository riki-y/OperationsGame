#include <NicoNico/NicoNico.h>
#include "NicoNicoCocosProgramStatistics.h"

using namespace niconico;

NicoNicoCocosProgramStatistics::NicoNicoCocosProgramStatistics() {
    
}

int NicoNicoCocosProgramStatistics::getWatchCount() {
    return (int)[NicoNico sharedInstance].publisher.program.statistics.watchCount;
}

int NicoNicoCocosProgramStatistics::getCommentCount() {
    return (int)[NicoNico sharedInstance].publisher.program.statistics.commentCount;
}

int NicoNicoCocosProgramStatistics::getTimeshiftReservationCount() {
    return (int)[NicoNico sharedInstance].publisher.program.statistics.timeshiftReservationCount;
}
