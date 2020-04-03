create table EQUIPE
(
Nom_Equipe varchar2(50) constraint pk_nom_equipe primary key,
Total_Joueur Number not null,
Score Number not Null,
Categorie varchar2(50) not null,
Manager_eq varchar2(50) not null
);

create table Contenir
(
id_j Number constraint fk_id_j references JOUEUR(ID_J),
Nom_eq VARCHAR2(50) constraint fk_nom_eq references EQUIPE(Nom_Equipe),
constraint pk_contenir primary key(id_j)
);

alter table EQUIPE add image_equipe varchar(50);

alter table EQUIPE Modify image_equipe varchar(50) not null;
