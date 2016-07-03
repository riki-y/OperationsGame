#include <NicoNico/NicoNico.h>
#include "NicoNicoCocosComment.h"

using namespace niconico;

NicoNicoCocosComment::NicoNicoCocosComment(int number, std::string body, NicoNicoCocosCommentPosition commentPosition, NicoNicoCocosCommentSize commentSize,
                                       int color, int vpos, bool mine)
: number(number),
body(body),
commentPosition(commentPosition),
commentSize(commentSize),
color(color),
vpos(vpos),
mine(mine) {
}

int NicoNicoCocosComment::getNumber() {
    return number;
}

int NicoNicoCocosComment::getColor() {
    return color;
}

std::string NicoNicoCocosComment::getText() {
    return body;
}

NicoNicoCocosCommentPosition niconico::NicoNicoCocosComment::getPosition() {
    return commentPosition;
}

NicoNicoCocosCommentSize niconico::NicoNicoCocosComment::getSize() {
    return commentSize;
}

int NicoNicoCocosComment::getVpos() {
    return vpos;
}

bool NicoNicoCocosComment::isMine() {
    return mine;
}
