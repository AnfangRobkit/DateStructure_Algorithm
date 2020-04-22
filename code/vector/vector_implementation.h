#pragma once
 /******************************************************************************************
 * 将vector各方法的实现部分，简洁地引入vector.h
 * 效果等同于将这些实现直接汇入vector.h
 * 如此可将定义与实现分离
 ******************************************************************************************/
#include"vector_expand.h"
#include"vector_shrink.h"
#include"vector_find_search.h"
#include "vector_insert.h"
#include"vector_remove.h"
#include"vector_dedeplicate.h"
#include"vector_traverse.h"