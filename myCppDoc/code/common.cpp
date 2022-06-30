#include "common.h"

Block::Block(const int& w, const int& h, const Class& c)
	:width(w),height(h),this_class(c){
}


bool Block::operator<(const Block& np) const {
	return this_class.name < np.this_class.name;
}