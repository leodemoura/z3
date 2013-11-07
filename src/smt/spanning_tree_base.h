/*++
Copyright (c) 2013 Microsoft Corporation

Module Name:

    spanning_tree_base.h

Abstract:

    Represent spanning trees with needed operations for Network Simplex

Author:

    Anh-Dung Phan (t-anphan) 2013-11-06

Notes:
   
--*/

#ifndef _SPANNING_TREE_BASE_H_
#define _SPANNING_TREE_BASE_H_

#include "util.h"
#include "vector.h"

namespace smt {
    template<typename TV>
    inline std::string pp_vector(std::string const & label, TV v, bool has_header = false) {
        std::ostringstream oss;
        if (has_header) {
            oss << "Index ";
            for (unsigned i = 0; i < v.size(); ++i) {
                oss << i << " ";
            }
            oss << std::endl;
        }
        oss << label << " ";
        for (unsigned i = 0; i < v.size(); ++i) {
            oss << v[i] << " ";
        }
        oss << std::endl;
        return oss.str();
    }

    class spanning_tree_base { 
    private:
        typedef int node;

    public:
        virtual void initialize(svector<bool> const & upwards, int num_nodes) {};

        /**
            \brief Get all descendants of a node including itself
        */
        virtual void get_descendants(node start, svector<node> & descendants) {};
        /**
            \brief Get all ancestors of a node including itself
        */
        virtual void get_ancestors(node start, svector<node> & ancestors) {};

        virtual node get_common_ancestor(node u, node v) {UNREACHABLE(); return -1;};
        virtual void update(node p, node q, node u, node v) {};
        virtual bool check_well_formed() {UNREACHABLE(); return false;};

        // TODO: remove these two unnatural functions
        virtual bool get_arc_direction(node start) const {UNREACHABLE(); return false;};
        virtual node get_parent(node start) {UNREACHABLE(); return -1;};
    };
}

#endif