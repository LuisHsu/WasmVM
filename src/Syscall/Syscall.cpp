/*
Copyright 2017 Luis Hsu, Kevin Cyu

Licensed under the Apache License, Version 2.0 (the "License");you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

#include <Syscall.h>

std::map<std::string, ModuleInst *>* Syscall::moduleInsts = nullptr;
void Syscall::initSyscall(std::map<std::string, ModuleInst *> *moduleInsts){
	Syscall::moduleInsts = moduleInsts;
}

void Syscall::handle(Store &store, Stack &coreStack){
	// Check value count
	if(coreStack.valueNum < 1){
		throw Exception("[unreachable] No value in the stack.", coreStack);
	}
	// Pop operand
	Value *operand = (Value *)coreStack.pop().data;
	if(operand->type != i32){
		throw Exception("[unreachable] Operand type is not i32.", coreStack);
	}
	// Call
	switch(operand->data.i32){
		case SYS_Read:
			// sys_read
			break;
		case SYS_Exit:
			Call::sysExit(coreStack);
		break;
		case SYS_Kill:
			Call::sysKill(coreStack);
		break;
		case SYS_Pause:
			Call::sysPause(coreStack);
		break;
		case SYS_Getpid:
			Call::sysGetpid(coreStack);
		break;
		default:
			throw Exception("[unreachable] Not implemented.", coreStack);
		break;
	}
	// Clean
	delete operand;
}