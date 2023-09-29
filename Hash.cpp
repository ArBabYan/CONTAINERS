#include <iostream>
#include <list>
#include <vector>
#include <string>

template <typename KeyType, typename ValueType>
class Hash
{
public:
	int size;
	std::vector<std::pair<KeyType, ValueType>> table;

	Hash(int initialSize = 100) : size(initialSize), table(initialSize) {}

	int hashFunction(const KeyType& key) const
	{
		int hash = 0;
		for (char c : key) {
			hash = hash * 31 + c;
		}
		return hash % size;
	}

	void insert(const KeyType& key, const ValueType& value)
	{
		int index = hashFunction(key);
		while (!table[index].first.empty())
		{
			index = (index + 1) % size;
		}
		table[index] = std::make_pair(key, value);
	}

	bool find(const KeyType& key, ValueType& value) const
	{
		int index = hashFunction(key);
		while (!table[index].first.empty())
		{
			if (table[index].first == key)
			{
				value = table[index].second;
				return true;
			}
			index = (index + 1) % size;
		}
		return false;
	}
};

int main()
{
	Hash<std::string, std::string> hash_Table;
	hash_Table.insert("BMW", "F90");
	hash_Table.insert("Audi", "RS8");
	hash_Table.insert("Porsche", "911 GT3 RS");
	std::string value;
	if (hash_Table.find("BMW", value))
	{
		std::cout << "found " << value << std::endl;
	}
	if (hash_Table.find("Audi", value))
	{
		std::cout << "found " << value << std::endl;
	}
	if (hash_Table.find("Porsche", value))
	{
		std::cout << "found " << value << std::endl;
	}
	else {
		std::cout << "not found" << std::endl;
	}

	return 0;
}
