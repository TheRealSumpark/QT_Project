--------------------------------------------------------
--  Fichier cr�� - jeudi-juin-11-2020   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table PARTENAIRE
--------------------------------------------------------

  CREATE TABLE "AHMED"."PARTENAIRE" 
   (	"NOM" VARCHAR2(20 BYTE), 
	"CIN" VARCHAR2(8 BYTE), 
	"ADRESSE" VARCHAR2(20 BYTE), 
	"DONS" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into AHMED.PARTENAIRE
SET DEFINE OFF;
--------------------------------------------------------
--  DDL for Index PARTENAIRE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "AHMED"."PARTENAIRE_PK" ON "AHMED"."PARTENAIRE" ("CIN") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table PARTENAIRE
--------------------------------------------------------

  ALTER TABLE "AHMED"."PARTENAIRE" ADD CONSTRAINT "PARTENAIRE_PK" PRIMARY KEY ("CIN")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "AHMED"."PARTENAIRE" MODIFY ("CIN" NOT NULL ENABLE);
