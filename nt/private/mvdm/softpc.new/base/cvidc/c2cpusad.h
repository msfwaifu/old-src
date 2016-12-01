/*[
 * Generated File: C2CpuSad.h
 *
]*/

char	*CpuVectorNames[] = {
	"Simulate",
	"Interrupt",
	"ClearHwInt",
	"EndOfApplication",
	"Terminate",
	"Initialise",
	"SetQuickEventCount",
	"GetQuickEventCount",
	"CalcQuickEventInstTime",
	"InitIOS",
	"DefineInb",
	"DefineInw",
	"DefineInd",
	"DefineOutb",
	"DefineOutw",
	"DefineOutd",
	"SetAL",
	"SetAH",
	"SetAX",
	"SetEAX",
	"SetBL",
	"SetBH",
	"SetBX",
	"SetEBX",
	"SetCL",
	"SetCH",
	"SetCX",
	"SetECX",
	"SetDL",
	"SetDH",
	"SetDX",
	"SetEDX",
	"SetSI",
	"SetESI",
	"SetDI",
	"SetEDI",
	"SetSP",
	"SetESP",
	"SetBP",
	"SetEBP",
	"SetIP",
	"SetEIP",
	"SetCS",
	"SetSS",
	"SetDS",
	"SetES",
	"SetFS",
	"SetGS",
	"SetEFLAGS",
	"SetSTATUS",
	"SetIOPL",
	"SetMSW",
	"SetCR0",
	"SetCR2",
	"SetCR3",
	"SetCF",
	"SetPF",
	"SetAF",
	"SetZF",
	"SetSF",
	"SetTF",
	"SetIF",
	"SetDF",
	"SetOF",
	"SetNT",
	"SetRF",
	"SetVM",
	"SetAC",
	"SetPE",
	"SetMP",
	"SetEM",
	"SetTS",
	"SetPG",
	"SetLDT_SELECTOR",
	"SetTR_SELECTOR",
	"GetAL",
	"GetAH",
	"GetAX",
	"GetEAX",
	"GetBL",
	"GetBH",
	"GetBX",
	"GetEBX",
	"GetCL",
	"GetCH",
	"GetCX",
	"GetECX",
	"GetDL",
	"GetDH",
	"GetDX",
	"GetEDX",
	"GetSI",
	"GetESI",
	"GetDI",
	"GetEDI",
	"GetSP",
	"GetESP",
	"GetBP",
	"GetEBP",
	"GetIP",
	"GetEIP",
	"GetCS",
	"GetSS",
	"GetDS",
	"GetES",
	"GetFS",
	"GetGS",
	"GetEFLAGS",
	"GetSTATUS",
	"GetIOPL",
	"GetMSW",
	"GetCR0",
	"GetCR2",
	"GetCR3",
	"GetCF",
	"GetPF",
	"GetAF",
	"GetZF",
	"GetSF",
	"GetTF",
	"GetIF",
	"GetDF",
	"GetOF",
	"GetNT",
	"GetRF",
	"GetVM",
	"GetAC",
	"GetPE",
	"GetMP",
	"GetEM",
	"GetTS",
	"GetET",
	"GetNE",
	"GetWP",
	"GetPG",
	"GetGDT_BASE",
	"GetGDT_LIMIT",
	"GetIDT_BASE",
	"GetIDT_LIMIT",
	"GetLDT_SELECTOR",
	"GetLDT_BASE",
	"GetLDT_LIMIT",
	"GetTR_SELECTOR",
	"GetTR_BASE",
	"GetTR_LIMIT",
	"GetTR_AR",
	"GetJumpCalibrateVal",
	"GetJumpInitialVal",
	"SetJumpInitialVal",
	"SetEOIEnable",
	"SetAddProfileData",
	"SetMaxProfileData",
	"GetAddProfileDataAddr",
	"PurgeLostIretHookLine"
};

char	*CpuPrivateVectorNames[] = {
	"GetSadInfoTable",
	"SetGDT_BASE_LIMIT",
	"SetIDT_BASE_LIMIT",
	"SetLDT_BASE_LIMIT",
	"SetTR_BASE_LIMIT",
	"SetTR_BASE_LIMIT_AR",
	"SetCS_BASE_LIMIT_AR",
	"SetSS_BASE_LIMIT_AR",
	"SetDS_BASE_LIMIT_AR",
	"SetES_BASE_LIMIT_AR",
	"SetFS_BASE_LIMIT_AR",
	"SetGS_BASE_LIMIT_AR",
	"SetCS_SELECTOR",
	"SetSS_SELECTOR",
	"SetDS_SELECTOR",
	"SetES_SELECTOR",
	"SetFS_SELECTOR",
	"SetGS_SELECTOR",
	"GetCS_SELECTOR",
	"GetSS_SELECTOR",
	"GetDS_SELECTOR",
	"GetES_SELECTOR",
	"GetFS_SELECTOR",
	"GetGS_SELECTOR",
	"GetCS_BASE",
	"GetSS_BASE",
	"GetDS_BASE",
	"GetES_BASE",
	"GetFS_BASE",
	"GetGS_BASE",
	"GetCS_LIMIT",
	"GetSS_LIMIT",
	"GetDS_LIMIT",
	"GetES_LIMIT",
	"GetFS_LIMIT",
	"GetGS_LIMIT",
	"GetCS_AR",
	"GetSS_AR",
	"GetDS_AR",
	"GetES_AR",
	"GetFS_AR",
	"GetGS_AR",
	"GetCPL",
	"SetCPL",
	"GetCpuState",
	"SetCpuState",
	"InitNanoCpu",
	"PrepareBlocksToCompile",
	"SetRegConstraint",
	"GrowRecPool",
	"BpiCompileBPI",
	"TrashIntelRegisters",
	"FmDeleteAllStructures",
	"ConstraintsFromUnivEpcPtr",
	"ConstraintsFromUnivHandle"
};

char	*SasVectorNames[] = {
	"Sas_memory_size",
	"Sas_connect_memory",
	"Sas_enable_20_bit_wrapping",
	"Sas_disable_20_bit_wrapping",
	"Sas_twenty_bit_wrapping_enabled",
	"Sas_memory_type",
	"Sas_hw_at",
	"Sas_w_at",
	"Sas_dw_at",
	"Sas_hw_at_no_check",
	"Sas_w_at_no_check",
	"Sas_dw_at_no_check",
	"Sas_store",
	"Sas_storew",
	"Sas_storedw",
	"Sas_store_no_check",
	"Sas_storew_no_check",
	"Sas_storedw_no_check",
	"Sas_loads",
	"Sas_stores",
	"Sas_loads_no_check",
	"Sas_stores_no_check",
	"Sas_move_bytes_forward",
	"Sas_move_words_forward",
	"Sas_move_doubles_forward",
	"Sas_move_bytes_backward",
	"Sas_move_words_backward",
	"Sas_move_doubles_backward",
	"Sas_fills",
	"Sas_fillsw",
	"Sas_fillsdw",
	"Sas_scratch_address",
	"Sas_transbuf_address",
	"Sas_loads_to_transbuf",
	"Sas_stores_from_transbuf",
	"Sas_PR8",
	"Sas_PR16",
	"Sas_PR32",
	"Sas_PW8",
	"Sas_PW16",
	"Sas_PW32",
	"Sas_PW8_no_check",
	"Sas_PW16_no_check",
	"Sas_PW32_no_check",
	"SasPtrToPhysAddrByte",
	"Sas_get_byte_addr",
	"SasPtrToLinAddrByte",
	"SasRegisterVirtualSelectors",
	"Sas_overwrite_memory",
	"Sas_PWS",
	"Sas_PWS_no_check",
	"Sas_PRS",
	"Sas_PRS_no_check",
	"Sas_PigCmpPage",
	"IOVirtualised"
};

char	*VideoVectorNames[] = {
	"GetVideolatches",
	"GetVideorplane",
	"GetVideowplane",
	"GetVideoscratch",
	"GetVideosr_masked_val",
	"GetVideosr_nmask",
	"GetVideodata_and_mask",
	"GetVideodata_xor_mask",
	"GetVideolatch_xor_mask",
	"GetVideobit_prot_mask",
	"GetVideoplane_enable",
	"GetVideoplane_enable_mask",
	"GetVideosr_lookup",
	"GetVideofwd_str_read_addr",
	"GetVideobwd_str_read_addr",
	"GetVideodirty_total",
	"GetVideodirty_low",
	"GetVideodirty_high",
	"GetVideovideo_copy",
	"GetVideomark_byte",
	"GetVideomark_word",
	"GetVideomark_string",
	"GetVideoread_shift_count",
	"GetVideoread_mapped_plane",
	"GetVideocolour_comp",
	"GetVideodont_care",
	"GetVideov7_bank_vid_copy_off",
	"GetVideoscreen_ptr",
	"GetVideorotate",
	"GetVideocalc_data_xor",
	"GetVideocalc_latch_xor",
	"GetVideoread_byte_addr",
	"GetVideov7_fg_latches",
	"GetVideoGC_regs",
	"GetVideolast_GC_index",
	"GetVideodither",
	"GetVideowrmode",
	"GetVideochain",
	"GetVideowrstate",
	"SetVideolatches",
	"SetVideorplane",
	"SetVideowplane",
	"SetVideoscratch",
	"SetVideosr_masked_val",
	"SetVideosr_nmask",
	"SetVideodata_and_mask",
	"SetVideodata_xor_mask",
	"SetVideolatch_xor_mask",
	"SetVideobit_prot_mask",
	"SetVideoplane_enable",
	"SetVideoplane_enable_mask",
	"SetVideosr_lookup",
	"SetVideofwd_str_read_addr",
	"SetVideobwd_str_read_addr",
	"SetVideodirty_total",
	"SetVideodirty_low",
	"SetVideodirty_high",
	"SetVideovideo_copy",
	"SetVideomark_byte",
	"SetVideomark_word",
	"SetVideomark_string",
	"SetVideoread_shift_count",
	"SetVideoread_mapped_plane",
	"SetVideocolour_comp",
	"SetVideodont_care",
	"SetVideov7_bank_vid_copy_off",
	"SetVideoscreen_ptr",
	"SetVideorotate",
	"SetVideocalc_data_xor",
	"SetVideocalc_latch_xor",
	"SetVideoread_byte_addr",
	"SetVideov7_fg_latches",
	"SetVideoGC_regs",
	"SetVideolast_GC_index",
	"SetVideodither",
	"SetVideowrmode",
	"SetVideochain",
	"SetVideowrstate",
	"setWritePointers",
	"setReadPointers",
	"setMarkPointers"
};

/*======================================== END ========================================*/
