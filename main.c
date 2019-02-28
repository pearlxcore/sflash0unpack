#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/stat.h>

/*
    0x0 <- Header
    0x1000 <- Unk
    0x2000 <- MBR1
    0x3000 <- MBR2
    0x4000 <- sflash0s0x32b (emc_ipl)
    0x64000 <- sflash0s0x32 (emc_ipl)
    0xC4000 <- sflash0s0x33 (eap_kbl)
    0x144000 <- sflash0s0x34 (wifi fw)
	0x1C4000 <- sflash0s0x38 (nvs)
    0x204000 <- sflash0s1.cryptx2b (sam_ipl)
    0x242000 <- sflash0s1.cryptx2 (sam_ipl)
    0x280000 <- sflash0s1.cryptx1 (idata)
    0x300000 <- sflash0s1.cryptx39 (bd_hrl?)
    0x380000 <- sflash0s1.cryptx6 (Virtual TRM)
    0x3C0000 <- sflash0s1.cryptx3b (secure loader, secure kernel, secure modules)
    0x1080000 <- sflash0s1.cryptx3 (secure loader, secure kernel, secure modules)
    0x1D40000 <- sflash0s1.cryptx40 (blank_region)
*/

typedef struct
{
	unsigned char header[0x1000];
	unsigned char unk[0x1000];
	unsigned char mbr1[0x1000];
	unsigned char mbr2[0x1000];
	unsigned char emc_iplb[0x60000];
	unsigned char emc_ipl[0x60000];
	unsigned char eap_kbl[0x80000];
	unsigned char wifi_fw[0x80000];
	unsigned char nvs[0x3C000];
	unsigned char header2[0x1000];
	unsigned char unk2[0x1000];
	unsigned char mbr3[0x1000];
	unsigned char mbr4[0x1000];
	unsigned char sam_iplb[0x3E000];
	unsigned char sam_ipl[0x3E000];
	unsigned char idata[0x80000];
	unsigned char bd_hrl[0x80000];
	unsigned char vtrm[0x40000];
	unsigned char secureb[0xCC0000];
	unsigned char secure[0xCC0000];
	unsigned char blank[0x2C0000];
} SFLASH0;

int main(int argc, char **argv){
	
	if(argc != 3){
		printf ("\nusage: sflash0unpack [sflash0] [outdir]  \n");
		return -1;
	}
	
	unsigned char out[256];
	
	mkdir(argv[2],0777);
	
	FILE *fp = fopen(argv[1],"rb");
	
	unsigned char *buf = (unsigned char*) malloc (0x2000000);
	
	fread(buf,0x2000000,1,fp);
	
	SFLASH0* entries = (SFLASH0*)buf;
	
	sprintf(out,"%s/header.bin",argv[2]);
	
	FILE *fl = fopen(out,"wb");
	
	fwrite(entries->header,sizeof(entries->header),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/emc_ipl.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->emc_ipl,sizeof(entries->emc_ipl),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/emc_iplb.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->emc_iplb,sizeof(entries->emc_iplb),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/eap_kbl.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->eap_kbl,sizeof(entries->eap_kbl),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/wifi_fw.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->wifi_fw,sizeof(entries->wifi_fw),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/sam_ipl.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->sam_ipl,sizeof(entries->sam_ipl),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/sam_iplb.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->sam_iplb,sizeof(entries->sam_iplb),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/idata.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->idata,sizeof(entries->idata),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/bd_hrl.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->bd_hrl,sizeof(entries->bd_hrl),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/vtrm.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->vtrm,sizeof(entries->vtrm),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/secure.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->secure,sizeof(entries->secure),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/secureb.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->secureb,sizeof(entries->secureb),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/blank.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->blank,sizeof(entries->blank),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/nvs.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->nvs,sizeof(entries->nvs),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/unk.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->unk,sizeof(entries->unk),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/mbr1.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->mbr1,sizeof(entries->mbr1),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/mbr2.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->mbr2,sizeof(entries->mbr2),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/unk2.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->unk2,sizeof(entries->unk2),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/mbr3.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->mbr3,sizeof(entries->mbr3),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/mbr4.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->mbr4,sizeof(entries->mbr4),1,fl);
	
	fclose(fl);
	
	sprintf(out,"%s/header2.bin",argv[2]);
	
	fl = fopen(out,"wb");
	
	fwrite(entries->header2,sizeof(entries->header2),1,fl);
	
	fclose(fl);
	
	fclose(fp);
	
	
	return 0;
}