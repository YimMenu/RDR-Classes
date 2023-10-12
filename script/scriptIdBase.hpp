#pragma once
#include <cstdint>
#include "../rage/joaat.hpp"

#pragma pack(push, 8)
namespace rage
{
	class datBitBuffer;
	class netLoggingInterface;
	class scrThread;

	class scriptIdBase
	{
	public:
		virtual ~scriptIdBase() = default;                           

		// Assumes the script thread's identity.
		virtual void FromThread(scrThread*) {};          

		// Returns whether the hash of the script id is valid.
		virtual bool IsValid() { return false; };                                  

		// Gets the hash of the script id.
		virtual joaat_t* GetHash(joaat_t* out) { return 0; };                  

		// Gets an unknown value from the script id.
		virtual std::uint32_t* GetInstanceHash(std::uint32_t* out) { return 0; };                      

		// Serializes the script id from the buffer.
		virtual void Deserialize(datBitBuffer* buffer) {};           

		// Serializes the script id to the buffer.
		virtual void Serialize(datBitBuffer* buffer) {};             

		// Calculates bitbuffer size.
		virtual std::uint32_t CalculateSize() { return 0; };                            

		// Calls _0x40 and returns its value added to another value. (packed size?)
		virtual std::uint32_t CalculateSize2() { return 0; };                            

		// Gets the hash of the script id again.
		virtual joaat_t GetHash2() { return 0; }

		// Copies the information of other to this object.
		virtual void FromScriptId(scriptIdBase* other) {}               

		// Returns whether the other script id is equal.
		virtual bool operator==(scriptIdBase*) { return false; };                   

		virtual bool SameScriptHash(scriptIdBase*) { return false; };                                
	};
}
#pragma pack(pop)