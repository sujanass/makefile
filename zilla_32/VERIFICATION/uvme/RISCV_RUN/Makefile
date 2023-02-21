run: info

info:
	@echo "-------info------"
	@echo "riscv_r_type_inst"
	@echo "riscv_i_type_inst"
	@echo "riscv_s_type_inst"
	@echo "riscv_sb_type_inst"
	@echo "riscv_u_type_inst"
	@echo "riscv_uj_type_inst"
	@echo "wave"
	@echo "-----------------"

riscv_r_type_inst:
	xrun -access +rwc -f compile_list.f +UVM_TESTNAME=riscv_r_type_inst -uvmhome CDNS-1.1d -seed 12
riscv_i_type_inst:
	xrun -access +rwc -f compile_list.f +UVM_TESTNAME=riscv_i_type_inst -uvmhome CDNS-1.1d -seed 13
riscv_s_type_inst:
	xrun -access +rwc -f compile_list.f +UVM_TESTNAME=riscv_s_type_inst -uvmhome CDNS-1.1d -seed 14
riscv_sb_type_inst:
	xrun -access +rwc -f compile_list.f +UVM_TESTNAME=riscv_sb_type_inst -uvmhome CDNS-1.1d -seed 15
riscv_u_type_inst:
	xrun -access +rwc -f compile_list.f +UVM_TESTNAME=riscv_u_type_inst -uvmhome CDNS-1.1d -seed 16
riscv_uj_type_inst:
	xrun -access +rwc -f compile_list.f +UVM_TESTNAME=riscv_uj_type_inst -uvmhome CDNS-1.1d -seed 17
wave:
	simvision wave.shm/ &




