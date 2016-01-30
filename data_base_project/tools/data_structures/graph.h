#ifndef _GRAPH_H_
#define _GRAPH_H_
#pragma once

#include "lib/Comparator.h"

namespace tools { 
namespace data_structures { 

// Graph abstract.
template<typename _Ty, 
         class _Compare = catdb::Comparator<_Ty>>
class Graph {
public:

};

// Matrix represented graph.
template<typename _Ty, 
         class _Compare = catdb::Comparator<_Ty>>
class matrix_graph : public Graph<_Ty, _Compare> { 

};

// Adjacency list represented graph.
template<typename _Ty,
         class _Compare = catdb::Comparator<_Ty>>
class adjacency_graph : public Graph<_Ty, _Compare> { 

};

} // data_structures namespace 
} // tools namespace 
#endif /* _GRAPH_H_ */
