#include <bits/stdc++.h>
using namespace std;

/// Importing policy_based_data_structure:

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

/// Importing ends here.

/// struct for declaring struct type pb_ds:

struct vals{
    int num;
    int typ;
    vals(int a,int b){
        num = a;
        typ = b;
    }
    bool operator <(const vals& other) const {
        if(num == other.num) return typ < other.typ;
        return num < other.num; /// num is the value on what basis it'll be sorted.
    }
};

/// typedef original name to pb_ds for simplicity:
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_ds;
/// struct type pb_ds:
typedef tree <vals, null_type, less<vals>, rb_tree_tag, tree_order_statistics_node_update> pb_ds_st;

int main(){
    /// Declaring a pb_ds(policy based ds):
    pb_ds treap;

    treap.insert(2);
    treap.insert(8);
    treap.insert(5);
    treap.insert(3);
    /// Return number of elements smaller than k:
    cout << treap.order_of_key(4) << endl; // 2

    /// Clear the treap:
    treap.clear();

    treap.insert(1);
    treap.insert(2);
    treap.insert(4);
    treap.insert(8);
    treap.insert(16);

    /// Return pointer to the k'th smallest number(0-based indexed):
    cout << *treap.find_by_order(1) << endl; // 2
    cout << *treap.find_by_order(2) << endl; // 4
    cout << *treap.find_by_order(4) << endl; // 16

    cout << treap.order_of_key(-5) << endl;  // 0
    cout << treap.order_of_key(11) << endl;  // 4
    cout << treap.order_of_key(50) << endl;  // 5

    /// If we want to get map but not the set, as the second argument type must be used mapped type.

    /// Tree supports all the operations of set including two new features:

    /// 1. find_by_order(k) :
    /// Returns an iterator to the k-th largest element (counting from zero).

    /// 2. order_of_key(k) :
    /// Returns the number of items in a set that are strictly smaller than k.



    /// The use of struct type policy based ds:

    pb_ds_st treap_st;

    treap_st.insert(vals(1,1));
    treap_st.insert(vals(40,2));
    treap_st.insert(vals(70,3));
    treap_st.insert(vals(15,4));
    treap_st.insert(vals(27,5));
    treap_st.insert(vals(27,6));
    treap_st.insert(vals(27,7));
    treap_st.insert(vals(45,6));

    pb_ds_st::iterator it;

    for(it = treap_st.begin();it!=treap_st.end();it++){
        vals v = *it;
        cout << v.num << " " << v.typ << endl;
    }
    
    it = treap_st.upper_bound(vals(27, 0));
    treap_st.erase(it); // erasing one 27 from treap , here {27, 5} will be erased//
    
    
    for(it = treap_st.begin();it!=treap_st.end();it++){
        vals v = *it;
        cout << v.num << " " << v.typ << endl;
    }
    
    return 0;
}
