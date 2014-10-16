
CREATE SEQUENCE public.storageoperations_operationid_seq_1;

CREATE TABLE public.storageOperations (
                operationID INTEGER NOT NULL DEFAULT nextval('public.storageoperations_operationid_seq_1'),
                name VARCHAR(64) NOT NULL,
                CONSTRAINT storageoperations_pk PRIMARY KEY (operationID)
);


ALTER SEQUENCE public.storageoperations_operationid_seq_1 OWNED BY public.storageOperations.operationID;

CREATE SEQUENCE public.files_file_id_seq;

CREATE TABLE public.files (
                file_id INTEGER NOT NULL DEFAULT nextval('public.files_file_id_seq'),
                name VARCHAR(1024) NOT NULL,
                filesize BIGINT NOT NULL,
                sha CHAR(512) NOT NULL,
                mimetype VARCHAR(255) NOT NULL,
                CONSTRAINT pk_files PRIMARY KEY (file_id)
);


ALTER SEQUENCE public.files_file_id_seq OWNED BY public.files.file_id;

CREATE SEQUENCE public.packages_case_id_seq;

CREATE TABLE public.packages (
                case_id INTEGER NOT NULL DEFAULT nextval('public.packages_case_id_seq'),
                name VARCHAR(255) NOT NULL,
                pinNr INTEGER,
                mountType VARCHAR(32),
                config OTHER,
                CONSTRAINT pk_packages PRIMARY KEY (case_id)
);


ALTER SEQUENCE public.packages_case_id_seq OWNED BY public.packages.case_id;

CREATE TABLE public.packages_files (
                case_id INTEGER NOT NULL,
                file_id INTEGER NOT NULL,
                CONSTRAINT packages_files_pk PRIMARY KEY (case_id, file_id)
);


CREATE SEQUENCE public.storage_id_seq;

CREATE TABLE public.storage (
                id INTEGER NOT NULL DEFAULT nextval('public.storage_id_seq'),
                name VARCHAR(255),
                creationDate TIMESTAMP DEFAULT now() NOT NULL,
                CONSTRAINT storage_pkey PRIMARY KEY (id)
);


ALTER SEQUENCE public.storage_id_seq OWNED BY public.storage.id;

CREATE UNIQUE INDEX storage_uk
 ON public.storage USING BTREE
 ( name );

CREATE SEQUENCE public.users_id_seq;

CREATE TABLE public.users (
                id INTEGER NOT NULL DEFAULT nextval('public.users_id_seq'),
                name VARCHAR(34) NOT NULL,
                password CHAR(64) NOT NULL,
                email VARCHAR(255) NOT NULL,
                phonenumber VARCHAR(32) NOT NULL,
                address LONGNVARCHAR NOT NULL,
                description LONGNVARCHAR NOT NULL,
                registrationdate TIMESTAMP DEFAULT now() NOT NULL,
                lastlogin TIMESTAMP,
                config OTHER,
                CONSTRAINT users_pkey PRIMARY KEY (id)
);


ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;

CREATE UNIQUE INDEX users_email_key
 ON public.users USING BTREE
 ( email );

CREATE UNIQUE INDEX users_name_key
 ON public.users USING BTREE
 ( name );

CREATE TABLE public.user_files (
                file_id INTEGER NOT NULL,
                user_id INTEGER NOT NULL,
                CONSTRAINT user_files_pk PRIMARY KEY (file_id, user_id)
);


CREATE TABLE public.user_storage (
                user_id INTEGER NOT NULL,
                storage_id INTEGER NOT NULL,
                CONSTRAINT user_storage_pk PRIMARY KEY (user_id, storage_id)
);


CREATE SEQUENCE public.parameters_id_seq;

CREATE TABLE public.parameters (
                parameter_id INTEGER NOT NULL DEFAULT nextval('public.parameters_id_seq'),
                name VARCHAR NOT NULL,
                config OTHER NOT NULL,
                CONSTRAINT parameters_pk PRIMARY KEY (parameter_id)
);


ALTER SEQUENCE public.parameters_id_seq OWNED BY public.parameters.parameter_id;

CREATE SEQUENCE public.groups_id_seq;

CREATE TABLE public.groups (
                group_id INTEGER NOT NULL DEFAULT nextval('public.groups_id_seq'),
                parent_id INTEGER,
                name VARCHAR(64) NOT NULL,
                description TEXT,
                creationTime TIMESTAMP DEFAULT NOW() NOT NULL,
                allowRecipe BOOLEAN DEFAULT false NOT NULL,
                allowItems BOOLEAN DEFAULT true NOT NULL,
                CONSTRAINT id PRIMARY KEY (group_id)
);


ALTER SEQUENCE public.groups_id_seq OWNED BY public.groups.group_id;

CREATE UNIQUE INDEX unique_child
 ON public.groups USING BTREE
 ( parent_id, name );

CREATE TABLE public.excludedGroups (
                id INTEGER NOT NULL,
                group_id INTEGER NOT NULL,
                CONSTRAINT excludedgroups_pk PRIMARY KEY (id, group_id)
);


CREATE TABLE public.groups_files (
                group_id INTEGER NOT NULL,
                file_id INTEGER NOT NULL,
                CONSTRAINT groups_files_pk PRIMARY KEY (group_id, file_id)
);


CREATE SEQUENCE public.items_item_id_seq;

CREATE TABLE public.items (
                item_id INTEGER NOT NULL DEFAULT nextval('public.items_item_id_seq'),
                users_id INTEGER NOT NULL,
                case_id INTEGER NOT NULL,
                group_id INTEGER NOT NULL,
                name VARCHAR(255) NOT NULL,
                symbol VARCHAR(255) NOT NULL,
                namespace VARCHAR(64) DEFAULT 'std' NOT NULL,
                creationDate TIMESTAMP DEFAULT now() NOT NULL,
                update TIMESTAMP NOT NULL,
                parameters OTHER NOT NULL,
                isRecipe BOOLEAN DEFAULT false NOT NULL,
                isItem BOOLEAN DEFAULT true NOT NULL,
                description TEXT,
                CONSTRAINT items_pk PRIMARY KEY (item_id)
);


ALTER SEQUENCE public.items_item_id_seq OWNED BY public.items.item_id;

CREATE UNIQUE INDEX items_symbol_uk
 ON public.items
 ( symbol );

CREATE SEQUENCE public.magazinelog_operation_id_seq;

CREATE TABLE public.magazineLog (
                operation_id INTEGER NOT NULL DEFAULT nextval('public.magazinelog_operation_id_seq'),
                operationID INTEGER NOT NULL,
                item_id INTEGER NOT NULL,
                change OTHER NOT NULL,
                CONSTRAINT magazinelog_pk PRIMARY KEY (operation_id, operationID, item_id)
);


ALTER SEQUENCE public.magazinelog_operation_id_seq OWNED BY public.magazineLog.operation_id;

CREATE TABLE public.items_files (
                item_id INTEGER NOT NULL,
                file_id INTEGER NOT NULL,
                CONSTRAINT items_files_pk PRIMARY KEY (item_id, file_id)
);


CREATE TABLE public.item_storage (
                item_id INTEGER NOT NULL,
                storage_id INTEGER NOT NULL,
                rack_name VARCHAR(255) NOT NULL,
                quantity DOUBLE PRECISION NOT NULL,
                CONSTRAINT pk_item_storage PRIMARY KEY (item_id, storage_id)
);


CREATE TABLE public.group_parameter (
                parameter_id INTEGER NOT NULL,
                group_id INTEGER NOT NULL,
                CONSTRAINT pk_parameters PRIMARY KEY (parameter_id, group_id)
);


ALTER TABLE public.magazineLog ADD CONSTRAINT storageoperations_magazinelog_fk
FOREIGN KEY (operationID)
REFERENCES public.storageOperations (operationID)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.items_files ADD CONSTRAINT files_items_files_fk
FOREIGN KEY (file_id)
REFERENCES public.files (file_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.packages_files ADD CONSTRAINT files_cases_files_fk
FOREIGN KEY (file_id)
REFERENCES public.files (file_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.user_files ADD CONSTRAINT files_users_files_fk
FOREIGN KEY (file_id)
REFERENCES public.files (file_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.groups_files ADD CONSTRAINT files_groups_files_fk
FOREIGN KEY (file_id)
REFERENCES public.files (file_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.items ADD CONSTRAINT cases_items_fk
FOREIGN KEY (case_id)
REFERENCES public.packages (case_id)
ON DELETE CASCADE
ON UPDATE CASCADE
NOT DEFERRABLE;

ALTER TABLE public.packages_files ADD CONSTRAINT cases_cases_files_fk
FOREIGN KEY (case_id)
REFERENCES public.packages (case_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.user_storage ADD CONSTRAINT user_magazines_storage_id_fkey
FOREIGN KEY (storage_id)
REFERENCES public.storage (id)
ON DELETE CASCADE
ON UPDATE CASCADE
NOT DEFERRABLE;

ALTER TABLE public.item_storage ADD CONSTRAINT storage_item_storage_fk
FOREIGN KEY (storage_id)
REFERENCES public.storage (id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.user_storage ADD CONSTRAINT users_user_storage_fk
FOREIGN KEY (user_id)
REFERENCES public.users (id)
ON DELETE CASCADE
ON UPDATE CASCADE
NOT DEFERRABLE;

ALTER TABLE public.user_files ADD CONSTRAINT users_users_files_fk
FOREIGN KEY (user_id)
REFERENCES public.users (id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.excludedGroups ADD CONSTRAINT users_excludedgroups_fk
FOREIGN KEY (id)
REFERENCES public.users (id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.items ADD CONSTRAINT users_items_fk
FOREIGN KEY (users_id)
REFERENCES public.users (id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.group_parameter ADD CONSTRAINT parameters_group_parameter_fk
FOREIGN KEY (parameter_id)
REFERENCES public.parameters (parameter_id)
ON DELETE CASCADE
ON UPDATE CASCADE
NOT DEFERRABLE;

ALTER TABLE public.group_parameter ADD CONSTRAINT groups_group_parameter_fk
FOREIGN KEY (group_id)
REFERENCES public.groups (group_id)
ON DELETE CASCADE
ON UPDATE CASCADE
NOT DEFERRABLE;

ALTER TABLE public.items ADD CONSTRAINT groups_items_fk
FOREIGN KEY (group_id)
REFERENCES public.groups (group_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.groups ADD CONSTRAINT groups_groups_fk
FOREIGN KEY (parent_id)
REFERENCES public.groups (group_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.groups_files ADD CONSTRAINT groups_groups_files_fk
FOREIGN KEY (group_id)
REFERENCES public.groups (group_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.excludedGroups ADD CONSTRAINT groups_excludedgroups_fk
FOREIGN KEY (group_id)
REFERENCES public.groups (group_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.item_storage ADD CONSTRAINT items_item_storage_fk
FOREIGN KEY (item_id)
REFERENCES public.items (item_id)
ON DELETE CASCADE
ON UPDATE CASCADE
NOT DEFERRABLE;

ALTER TABLE public.items_files ADD CONSTRAINT items_items_files_fk
FOREIGN KEY (item_id)
REFERENCES public.items (item_id)
ON DELETE NO ACTION
ON UPDATE NO ACTION
NOT DEFERRABLE;

ALTER TABLE public.magazineLog ADD CONSTRAINT items_magazinelog_fk
FOREIGN KEY (item_id)
REFERENCES public.items (item_id)
ON DELETE NO ACTION
ON UPDATE CASCADE
NOT DEFERRABLE;
