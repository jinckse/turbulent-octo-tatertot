@@ -0,0 +1,48 @@
// Top-down red-black tree header file - lab 3 summer 15

// These will have to change if data in node is more than just an int.
typedef int Key;
typedef Key Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (key(A) == key(B))

typedef struct STnode* link;

struct STnode 
{
	int N;
	Item item;  // Data for this node
	link l, r;  // left & right links
	char red;   // RB color
	int RRodd;   // Subtree odd root rank
};

extern Item NULLitem;

void STinit();          // Initialize tree with just a sentinel

Item STsearch(Key v);   // Find node for a key

int SToddRankOfMax();   // No key can have a rank larger than this

Item STselectSmall(int k);  // Find node with smallest key for a odd rank
Item STselectLarge(int k);  // Find node with largest key for an odd rank

int STinvSelect(Key v); // Inverse of STselect

void extendedTraceOn(); // Full tracing of intermediate trees

void basicTraceOn();    // Just trace down and up passes for insert

void traceOff();        // Run silent

void STinsert(Item item);     // Insert an item.  No uniqueness check

void verifyRBproperties();    // Ensure that tree isn't damaged

void STprintTree();           // Dumps out tree

void cleanUpUnbalanced(link h);  // Includes subtree sizes and verifies a tree
                                 // built without balancing
