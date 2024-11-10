# Blockchain

![image](https://github.com/user-attachments/assets/7fc7905a-6f21-418e-aba9-772be8365e4e)


https://github.com/libbitcoin/libbitcoin-system
![image](https://github.com/user-attachments/assets/e536954e-5932-45d0-92a6-778d4fb38f7d)

Community
![image](https://github.com/user-attachments/assets/de57b355-d7a3-42c5-806a-3a989fe319c8)

Visual Studio File > Open > Project/Solution randame kelia iki libbitcoin-system.sln (libbitcoin-system\builds\msvc\vs2022), atidarome solution faila ir spaudziame Build > Build Solution. Susiduriau su NuGet package missing erroru ir turejau atlikti siuos veiksmus: Tools > Options > NuGet Package Manager > General ir pazymim laukelius: 
- Automatically check for missing packages during build;
- Allow NuGet to download missing packages during build;

Tada desiniuoju klavisu ant Solution, Solution Explorer langelyje ir pasirenkame Restore NuGet Packages.

Po restor'o galime is naujo pabuildinti solutiona: Build > Build Solution.

Dabar galime kurti jau savo programas su <bitcoin/bitcoin.hpp< biblioteka.

Sukure nauja faila nurodome Include Additional directories kelia iki bitcoin.hpp failo

Programa:
<details>
  <summary> Perziureti koda </summary>

```


  #include <bitcoin/bitcoin.hpp>
  bc::hash_digest create_merkle(bc::hash_list& merkle)
{
 if (merkle.empty())		
  return bc::null_hash;	
 else if (merkle.size() == 1)	
  return merkle[0];	
 while (merkle.size() > 1)
	{		
  if (merkle.size() % 2 != 0)
   merkle.push_back(merkle.back());
   assert(merkle.size() % 2 == 0);
   bc::hash_list new_merkle;
   for (auto it = merkle.begin(); it != merkle.end(); it += 2)
		{
   bc::data_chunk concat_data(bc::hash_size * 2);
   auto concat = bc::serializer<
  decltype(concat_data.begin())>(concat_data.begin());
			concat.write_hash(*it);
			concat.write_hash(*(it + 1));
bc::hash_digest new_root = bc::bitcoin_hash(concat_data);
   new_merkle.push_back(new_root);
		}
  merkle = new_merkle;
		// DEBUG output -------------------------------------
		std::cout << "Current merkle hash list:" << std::endl;
		for (const auto& hash : merkle)
			std::cout << " " << bc::encode_base16(hash) << std::endl;
		std::cout << std::endl;
		// --------------------------------------------------
	}
	// Finally we end up with a single item.
	return merkle[0];
}
int main()
{
	// Transactions hashes from a block (#100 000) to reproduce the same merkle root
	bc::hash_list tx_hashes{ {
	bc::hash_literal("8c14f0db3df150123e6f3dbbf30f8b955a8249b62ac1d1ff16284aefa3d06d87"),
	bc::hash_literal("fff2525b8931402dd09222c50775608f75787bd2b87e56995a7bdd30f79702c4"),
	bc::hash_literal("6359f0868171b1d194cbee1af2f16ea598ae8fad666d9b012c8ed2b79a236ec4"),
	bc::hash_literal("e9a66845e05d5abc0ad04ec80f774a7e585c6e8db975962d069a522137b80c1d"),
	} };
	const bc::hash_digest merkle_root = create_merkle(tx_hashes);
	std::cout << "Merkle Root Hash: " << bc::encode_base16(merkle_root) << std::endl;
	// std::cout << "Merkle Root Hash-2: " << bc::encode_hash(merkle_root) << std::endl;
	return 0;
}
 ```

</details>

Galime buildinti programa. Susiduriau su errorais:

![image](https://github.com/user-attachments/assets/b56dc781-a9db-419f-82a8-0a650f32e41a)

Githubo repozitorijoje nebuvo failo bitcoin.hpp

build_all.bat
nu get environment variable
![image](https://github.com/user-attachments/assets/8b797702-976c-49ee-93f0-23c95d41a454)

system.hpp
![image](https://github.com/user-attachments/assets/3f8a3357-7d18-4c22-85ac-86b2d60db516)


![image](https://github.com/user-attachments/assets/7eb9c1d4-9d8f-4026-b630-ae3c5394e7bd)
![image](https://github.com/user-attachments/assets/89ed0a07-73ac-482a-a672-645288d6d646)


