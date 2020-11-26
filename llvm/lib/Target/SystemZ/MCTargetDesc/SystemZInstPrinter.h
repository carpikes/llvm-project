//==- SystemZInstPrinter.h - Convert SystemZ MCInst to assembly --*- C++ -*-==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This class prints a SystemZ MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_SYSTEMZ_MCTARGETDESC_SYSTEMZINSTPRINTER_H
#define LLVM_LIB_TARGET_SYSTEMZ_MCTARGETDESC_SYSTEMZINSTPRINTER_H

#include "llvm/MC/MCInstPrinter.h"
#include <cstdint>

namespace llvm {

class MCOperand;

class SystemZInstPrinter : public MCInstPrinter {
public:
  SystemZInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                     const MCRegisterInfo &MRI)
    : MCInstPrinter(MAI, MII, MRI) {}

  // Automatically generated by tblgen.
  void printInstruction(const MCInst *MI, uint64_t Address, raw_ostream &O);
  static const char *getRegisterName(unsigned RegNo);

  // Print an address with the given base, displacement and index.
  static void printAddress(unsigned Base, int64_t Disp, unsigned Index,
                           raw_ostream &O, bool UseMarkup);

  // Print the given operand.
  static void printOperand(const MCOperand &MO, const MCAsmInfo *MAI,
                           raw_ostream &O, bool UseMarkup);

  // Override MCInstPrinter.
  void printRegName(raw_ostream &O, unsigned RegNo) const override;
  void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                 const MCSubtargetInfo &STI, raw_ostream &O) override;

private:
  // Print various types of operand.
  void printOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printBDAddrOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printBDXAddrOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printBDLAddrOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printBDRAddrOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printBDVAddrOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printU1ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printU2ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printU3ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printU4ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printU6ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printS8ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printU8ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printU12ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printS16ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printU16ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printS32ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printU32ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printU48ImmOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printPCRelOperand(const MCInst *MI, int OpNum, raw_ostream &O);
  void printPCRelTLSOperand(const MCInst *MI, int OpNum, raw_ostream &O);

  // Print the mnemonic for a condition-code mask ("ne", "lh", etc.)
  // This forms part of the instruction name rather than the operand list.
  void printCond4Operand(const MCInst *MI, int OpNum, raw_ostream &O);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_SYSTEMZ_MCTARGETDESC_SYSTEMZINSTPRINTER_H
