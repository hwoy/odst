#include "Carray.h"
#include "Ccirlinklist.h"
#include "Cdeque.h"
#include "Cdynamicarray.h"
#include "Citerator.h"
#include "Clinklist.h"
#include "Clinklist_interface.h"
#include "Cqueue.h"
#include "Cset.h"
#include "Cstack.h"
#include "Cstaticarray.h"
#include "Cutil.h"
#include "Cvector.h"

namespace odst{

template <typename U,unsigned int N>
using array = Carray<U,N>;

template <typename U>
using vector = Cvector<U,Cdynamicarray<U>>;

template <typename U>
using list = Cvector<U,Clinklist_interface<U,2,Cnode<U,2>,Clist_base<U>>>;

template <typename U>
using list_forward = Cvector<U,Clinklist_interface<U,1,Cnode<U,1>,Clist_forward_base<U>>>;
}
