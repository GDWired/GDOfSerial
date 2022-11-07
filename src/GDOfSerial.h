#ifndef GDOFSERIAL
#define GDOFSERIAL

#include <Godot.hpp>
#include <Reference.hpp>
#include <ofSerial.h>

using namespace godot;

namespace godot {

	class GDOfSerial : public Reference {
		GODOT_CLASS(GDOfSerial, Reference)

		// Private attributs
		private:
		
		// Private methods
		private:

			//###############################################################
			//	Internals
			//###############################################################

			//###############################################################
			//	Wrapped methods
			//###############################################################

		// Public methods
		public:

			//###############################################################
			//	Constructor
			//###############################################################

			/**
			 * Constructor
			 */
			GDOfSerial();

			/**
			 * Destructor
			 */
			~GDOfSerial();

			//###############################################################
			//	Godot methods
			//###############################################################

			/**
			 * Bind methods, signals etc.
			 */
			static void _register_methods();

			/**
			 * Init the class
			 */
			void _init();

			//###############################################################
			//	Callbacks
			//###############################################################

			//###############################################################
			//	Emit handlers
			//###############################################################
	};
}

#endif // GDOFSERIAL
