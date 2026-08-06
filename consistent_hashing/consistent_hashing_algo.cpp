#include<bits/stdc++.h>
using namespace std;

class ConsistentHashRing{
    private:
        map<int, string> ring; // Hash ring
        set<int> sorted_keys;
        int num_virtual_nodes; // Number of virtual nodes per physical node

        // Hash function to generate hash value for a given key
        int hashFunction(const string& key) {
            hash<string> hasher;
            return hasher(key);
        }

    public:
        ConsistentHashRing(int virtual_nodes = 3) : num_virtual_nodes(virtual_nodes) {}

        // Add a physical node to the hash ring
        void addNode(const string& node) {
            for (int i = 0; i < num_virtual_nodes; ++i) {
                string virtual_node = node + "#" + to_string(i);
                int hash_value = hashFunction(virtual_node);
                ring[hash_value] = node;
                sorted_keys.insert(hash_value);
            }
        }

        // Remove a physical node from the hash ring
        void removeNode(const string& node) {
            for (int i = 0; i < num_virtual_nodes; ++i) {
                string virtual_node = node + "#" + to_string(i);
                int hash_value = hashFunction(virtual_node);
                ring.erase(hash_value);
                sorted_keys.erase(hash_value);          
            }
        }

        string get_node(const string& key) {
            if (ring.empty()) {
                return ""; // No nodes in the ring
            }
            int hash_value = hashFunction(key);
            auto it = sorted_keys.lower_bound(hash_value);
            if (it == sorted_keys.end()) {
                it = sorted_keys.begin(); // Wrap around to the first node
            }
            return ring[*it];
        }
        
    };

    int main(){
        ConsistentHashRing hashRing(3); // Create a consistent hash ring with 3 virtual nodes per physical node

        // Add physical nodes to the hash ring
        hashRing.addNode("Node1");
        hashRing.addNode("Node2");
        hashRing.addNode("Node3");

        // Get the node responsible for a given key
        string key = "my_key";
        string responsible_node = hashRing.get_node(key);
        cout << "Key: " << key << " is mapped to Node: " << responsible_node << endl;

        // Remove a node and check the mapping again
        hashRing.removeNode("Node3");
        responsible_node = hashRing.get_node(key);
        cout << "After removing Node3, Key: " << key << " is now mapped to Node: " << responsible_node << endl;
    
        return 0;
    }
