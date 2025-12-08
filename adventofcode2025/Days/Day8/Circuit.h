#include <set>
#include "Box.h"

/// <summary>
/// Circuit class, holds a list of Boxes that make up the Circuit.
/// </summary>
class Circuit {
private:
	std::set<Box*> circuit = std::set<Box*>();

	/// <summary>
	/// Get the list of Boxes that are in this Circuit.
	/// </summary>
	/// <returns>list of Boxes</returns>
	std::set<Box*>* getBoxes();
public:
	Circuit();

	/// <summary>
	/// Check if the given Box is in the Circuit.
	/// </summary>
	/// <param name="b"></param>
	/// <returns>Bool True if Box* b is in the Circuit.</returns>
	bool containsBox(Box* b);

	/// <summary>
	///		Merge the given Circuit into this Circuit.
	/// </summary>
	/// <param name="c">The Circuit to be merged.</param>
	void merge(Circuit* c);

	/// <summary>
	/// Insert the given Box into this Circuit
	/// </summary>
	/// <param name="b">The Box to be inserted.</param>
	void insertBox(Box* b);

	int getSize();

	
};