// File created from ../../../src/lib/dhcpsrv/dhcpsrv_messages.mes

#ifndef DHCPSRV_MESSAGES_H
#define DHCPSRV_MESSAGES_H

#include <log/message_types.h>

namespace isc {
namespace dhcp {

extern const isc::log::MessageID DHCPSRV_CFGMGR_ADD_IFACE;
extern const isc::log::MessageID DHCPSRV_CFGMGR_ADD_SUBNET4;
extern const isc::log::MessageID DHCPSRV_CFGMGR_ADD_SUBNET6;
extern const isc::log::MessageID DHCPSRV_CFGMGR_ALL_IFACES_ACTIVE;
extern const isc::log::MessageID DHCPSRV_CFGMGR_CFG_DHCP_DDNS;
extern const isc::log::MessageID DHCPSRV_CFGMGR_CLEAR_ACTIVE_IFACES;
extern const isc::log::MessageID DHCPSRV_CFGMGR_CONFIG4_MERGED;
extern const isc::log::MessageID DHCPSRV_CFGMGR_CONFIG6_MERGED;
extern const isc::log::MessageID DHCPSRV_CFGMGR_CONFIGURE_SERVERID;
extern const isc::log::MessageID DHCPSRV_CFGMGR_DDNS_PARAMETER_IGNORED;
extern const isc::log::MessageID DHCPSRV_CFGMGR_DDNS_PARAMETER_MOVED;
extern const isc::log::MessageID DHCPSRV_CFGMGR_DEL_SUBNET4;
extern const isc::log::MessageID DHCPSRV_CFGMGR_DEL_SUBNET6;
extern const isc::log::MessageID DHCPSRV_CFGMGR_FLQ_POPULATE_FREE_ADDRESS_LEASES;
extern const isc::log::MessageID DHCPSRV_CFGMGR_FLQ_POPULATE_FREE_ADDRESS_LEASES_DONE;
extern const isc::log::MessageID DHCPSRV_CFGMGR_FLQ_POPULATE_FREE_PREFIX_LEASES;
extern const isc::log::MessageID DHCPSRV_CFGMGR_FLQ_POPULATE_FREE_PREFIX_LEASES_DONE;
extern const isc::log::MessageID DHCPSRV_CFGMGR_IPV4_RESERVATIONS_NON_UNIQUE_IGNORED;
extern const isc::log::MessageID DHCPSRV_CFGMGR_IPV6_RESERVATIONS_NON_UNIQUE_IGNORED;
extern const isc::log::MessageID DHCPSRV_CFGMGR_IP_RESERVATIONS_UNIQUE_DUPLICATES_POSSIBLE;
extern const isc::log::MessageID DHCPSRV_CFGMGR_NEW_SUBNET4;
extern const isc::log::MessageID DHCPSRV_CFGMGR_NEW_SUBNET6;
extern const isc::log::MessageID DHCPSRV_CFGMGR_NO_SUBNET4;
extern const isc::log::MessageID DHCPSRV_CFGMGR_NO_SUBNET6;
extern const isc::log::MessageID DHCPSRV_CFGMGR_ONLY_SUBNET4;
extern const isc::log::MessageID DHCPSRV_CFGMGR_ONLY_SUBNET6;
extern const isc::log::MessageID DHCPSRV_CFGMGR_OPTION_DUPLICATE;
extern const isc::log::MessageID DHCPSRV_CFGMGR_RELAY_IP_ADDRESS_DEPRECATED;
extern const isc::log::MessageID DHCPSRV_CFGMGR_RENEW_GTR_REBIND;
extern const isc::log::MessageID DHCPSRV_CFGMGR_SOCKET_RAW_UNSUPPORTED;
extern const isc::log::MessageID DHCPSRV_CFGMGR_SOCKET_TYPE_DEFAULT;
extern const isc::log::MessageID DHCPSRV_CFGMGR_SOCKET_TYPE_SELECT;
extern const isc::log::MessageID DHCPSRV_CFGMGR_SUBNET4;
extern const isc::log::MessageID DHCPSRV_CFGMGR_SUBNET4_ADDR;
extern const isc::log::MessageID DHCPSRV_CFGMGR_SUBNET4_IFACE;
extern const isc::log::MessageID DHCPSRV_CFGMGR_SUBNET4_RELAY;
extern const isc::log::MessageID DHCPSRV_CFGMGR_SUBNET6;
extern const isc::log::MessageID DHCPSRV_CFGMGR_SUBNET6_IFACE;
extern const isc::log::MessageID DHCPSRV_CFGMGR_SUBNET6_IFACE_ID;
extern const isc::log::MessageID DHCPSRV_CFGMGR_SUBNET6_RELAY;
extern const isc::log::MessageID DHCPSRV_CFGMGR_UNICAST_LINK_LOCAL;
extern const isc::log::MessageID DHCPSRV_CFGMGR_UPDATE_SUBNET4;
extern const isc::log::MessageID DHCPSRV_CFGMGR_UPDATE_SUBNET6;
extern const isc::log::MessageID DHCPSRV_CFGMGR_USE_ADDRESS;
extern const isc::log::MessageID DHCPSRV_CFGMGR_USE_ALLOCATOR;
extern const isc::log::MessageID DHCPSRV_CFGMGR_USE_UNICAST;
extern const isc::log::MessageID DHCPSRV_CLOSE_DB;
extern const isc::log::MessageID DHCPSRV_DDNS_TTL_PERCENT_TOO_SMALL;
extern const isc::log::MessageID DHCPSRV_DEPRECATED;
extern const isc::log::MessageID DHCPSRV_DHCP4O6_RECEIVED_BAD_PACKET;
extern const isc::log::MessageID DHCPSRV_DHCP_DDNS_ERROR_EXCEPTION;
extern const isc::log::MessageID DHCPSRV_DHCP_DDNS_HANDLER_NULL;
extern const isc::log::MessageID DHCPSRV_DHCP_DDNS_NCR_REJECTED;
extern const isc::log::MessageID DHCPSRV_DHCP_DDNS_NCR_SENT;
extern const isc::log::MessageID DHCPSRV_DHCP_DDNS_SENDER_STARTED;
extern const isc::log::MessageID DHCPSRV_DHCP_DDNS_SENDER_STOPPED;
extern const isc::log::MessageID DHCPSRV_DHCP_DDNS_SUSPEND_UPDATES;
extern const isc::log::MessageID DHCPSRV_HOOK_LEASE4_RECOVER_SKIP;
extern const isc::log::MessageID DHCPSRV_HOOK_LEASE4_RENEW_SKIP;
extern const isc::log::MessageID DHCPSRV_HOOK_LEASE4_SELECT_SKIP;
extern const isc::log::MessageID DHCPSRV_HOOK_LEASE6_EXTEND_SKIP;
extern const isc::log::MessageID DHCPSRV_HOOK_LEASE6_RECOVER_SKIP;
extern const isc::log::MessageID DHCPSRV_HOOK_LEASE6_SELECT_SKIP;
extern const isc::log::MessageID DHCPSRV_INVALID_ACCESS;
extern const isc::log::MessageID DHCPSRV_LEASE4_EXTENDED_INFO_SANITY_FAIL;
extern const isc::log::MessageID DHCPSRV_LEASE4_EXTENDED_INFO_UPGRADED;
extern const isc::log::MessageID DHCPSRV_LEASE6_EXTENDED_INFO_SANITY_FAIL;
extern const isc::log::MessageID DHCPSRV_LEASE6_EXTENDED_INFO_UPGRADED;
extern const isc::log::MessageID DHCPSRV_LEASE_MGR_CALLBACK_EXCEPTION;
extern const isc::log::MessageID DHCPSRV_LEASE_MGR_CALLBACK_UNKNOWN_EXCEPTION;
extern const isc::log::MessageID DHCPSRV_LEASE_SANITY_FAIL;
extern const isc::log::MessageID DHCPSRV_LEASE_SANITY_FAIL_DISCARD;
extern const isc::log::MessageID DHCPSRV_LEASE_SANITY_FIXED;
extern const isc::log::MessageID DHCPSRV_MEMFILE_ADD_ADDR4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_ADD_ADDR6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_BEGIN_BUILD_EXTENDED_INFO_TABLES6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_BEGIN_EXTRACT_EXTENDED_INFO4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_BEGIN_TRANSACTION;
extern const isc::log::MessageID DHCPSRV_MEMFILE_BUILD_EXTENDED_INFO_TABLES6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_BUILD_EXTENDED_INFO_TABLES6_ERROR;
extern const isc::log::MessageID DHCPSRV_MEMFILE_COMMIT;
extern const isc::log::MessageID DHCPSRV_MEMFILE_CONVERTING_LEASE_FILES;
extern const isc::log::MessageID DHCPSRV_MEMFILE_DB;
extern const isc::log::MessageID DHCPSRV_MEMFILE_DELETE_ADDR;
extern const isc::log::MessageID DHCPSRV_MEMFILE_DELETE_EXPIRED_RECLAIMED4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_DELETE_EXPIRED_RECLAIMED6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_DELETE_EXPIRED_RECLAIMED_START;
extern const isc::log::MessageID DHCPSRV_MEMFILE_EXTRACT_EXTENDED_INFO4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_EXTRACT_EXTENDED_INFO4_ERROR;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET6_DUID;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_ADDR4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_ADDR6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_CLIENTID;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_EXPIRED4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_EXPIRED6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_HOSTNAME4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_HOSTNAME6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_HWADDR;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_IAID_DUID;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_IAID_SUBID_DUID;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_LINKADDR6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_PAGE4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_PAGE6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_RELAYID4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_RELAYID6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_REMOTEID4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_REMOTEID6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_SUBID4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_SUBID6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_SUBID_CLIENTID;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_SUBID_HWADDR;
extern const isc::log::MessageID DHCPSRV_MEMFILE_GET_VERSION;
extern const isc::log::MessageID DHCPSRV_MEMFILE_LEASE_FILE_LOAD;
extern const isc::log::MessageID DHCPSRV_MEMFILE_LEASE_LOAD;
extern const isc::log::MessageID DHCPSRV_MEMFILE_LEASE_LOAD_ROW_ERROR;
extern const isc::log::MessageID DHCPSRV_MEMFILE_LFC_EXECUTE;
extern const isc::log::MessageID DHCPSRV_MEMFILE_LFC_LEASE_FILE_RENAME_FAIL;
extern const isc::log::MessageID DHCPSRV_MEMFILE_LFC_LEASE_FILE_REOPEN_FAIL;
extern const isc::log::MessageID DHCPSRV_MEMFILE_LFC_SETUP;
extern const isc::log::MessageID DHCPSRV_MEMFILE_LFC_SPAWN_FAIL;
extern const isc::log::MessageID DHCPSRV_MEMFILE_LFC_START;
extern const isc::log::MessageID DHCPSRV_MEMFILE_LFC_UNREGISTER_TIMER_FAILED;
extern const isc::log::MessageID DHCPSRV_MEMFILE_NEEDS_DOWNGRADING;
extern const isc::log::MessageID DHCPSRV_MEMFILE_NEEDS_UPGRADING;
extern const isc::log::MessageID DHCPSRV_MEMFILE_NO_STORAGE;
extern const isc::log::MessageID DHCPSRV_MEMFILE_READ_HWADDR_FAIL;
extern const isc::log::MessageID DHCPSRV_MEMFILE_ROLLBACK;
extern const isc::log::MessageID DHCPSRV_MEMFILE_UPDATE_ADDR4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_UPDATE_ADDR6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_WIPE_LEASES4;
extern const isc::log::MessageID DHCPSRV_MEMFILE_WIPE_LEASES4_FINISHED;
extern const isc::log::MessageID DHCPSRV_MEMFILE_WIPE_LEASES6;
extern const isc::log::MessageID DHCPSRV_MEMFILE_WIPE_LEASES6_FINISHED;
extern const isc::log::MessageID DHCPSRV_MT_DISABLED_QUEUE_CONTROL;
extern const isc::log::MessageID DHCPSRV_MULTIPLE_RAW_SOCKETS_PER_IFACE;
extern const isc::log::MessageID DHCPSRV_MYSQL_ADD_ADDR4;
extern const isc::log::MessageID DHCPSRV_MYSQL_ADD_ADDR6;
extern const isc::log::MessageID DHCPSRV_MYSQL_BEGIN_TRANSACTION;
extern const isc::log::MessageID DHCPSRV_MYSQL_COMMIT;
extern const isc::log::MessageID DHCPSRV_MYSQL_DB;
extern const isc::log::MessageID DHCPSRV_MYSQL_DELETED_EXPIRED_RECLAIMED;
extern const isc::log::MessageID DHCPSRV_MYSQL_DELETE_ADDR;
extern const isc::log::MessageID DHCPSRV_MYSQL_DELETE_EXPIRED_RECLAIMED4;
extern const isc::log::MessageID DHCPSRV_MYSQL_DELETE_EXPIRED_RECLAIMED6;
extern const isc::log::MessageID DHCPSRV_MYSQL_FATAL_ERROR;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET4;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET6;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_ADDR4;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_ADDR6;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_CLIENTID;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_DUID;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_EXPIRED4;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_EXPIRED6;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_HOSTNAME4;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_HOSTNAME6;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_HWADDR;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_IAID_DUID;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_IAID_SUBID_DUID;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_LINKADDR6;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_PAGE4;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_PAGE6;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_RELAYID4;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_RELAYID6;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_REMOTEID4;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_REMOTEID6;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_SUBID4;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_SUBID6;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_SUBID_CLIENTID;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_SUBID_HWADDR;
extern const isc::log::MessageID DHCPSRV_MYSQL_GET_VERSION;
extern const isc::log::MessageID DHCPSRV_MYSQL_HOST_DB;
extern const isc::log::MessageID DHCPSRV_MYSQL_HOST_DB_GET_VERSION;
extern const isc::log::MessageID DHCPSRV_MYSQL_HOST_DB_READONLY;
extern const isc::log::MessageID DHCPSRV_MYSQL_HOST_DB_RECONNECT_ATTEMPT_FAILED;
extern const isc::log::MessageID DHCPSRV_MYSQL_HOST_DB_RECONNECT_ATTEMPT_SCHEDULE;
extern const isc::log::MessageID DHCPSRV_MYSQL_HOST_DB_RECONNECT_FAILED;
extern const isc::log::MessageID DHCPSRV_MYSQL_LEASE_DB_RECONNECT_ATTEMPT_FAILED;
extern const isc::log::MessageID DHCPSRV_MYSQL_LEASE_DB_RECONNECT_ATTEMPT_SCHEDULE;
extern const isc::log::MessageID DHCPSRV_MYSQL_LEASE_DB_RECONNECT_FAILED;
extern const isc::log::MessageID DHCPSRV_MYSQL_NEGATIVE_LEASES_STAT;
extern const isc::log::MessageID DHCPSRV_MYSQL_NO_TLS;
extern const isc::log::MessageID DHCPSRV_MYSQL_ROLLBACK;
extern const isc::log::MessageID DHCPSRV_MYSQL_START_TRANSACTION;
extern const isc::log::MessageID DHCPSRV_MYSQL_TLS_CIPHER;
extern const isc::log::MessageID DHCPSRV_MYSQL_UPDATE_ADDR4;
extern const isc::log::MessageID DHCPSRV_MYSQL_UPDATE_ADDR6;
extern const isc::log::MessageID DHCPSRV_MYSQL_UPGRADE_BINARY_ADDRESS6;
extern const isc::log::MessageID DHCPSRV_MYSQL_UPGRADE_BINARY_ADDRESS6_ERROR;
extern const isc::log::MessageID DHCPSRV_MYSQL_UPGRADE_BINARY_ADDRESS6_PAGE;
extern const isc::log::MessageID DHCPSRV_MYSQL_UPGRADE_EXTENDED_INFO4;
extern const isc::log::MessageID DHCPSRV_MYSQL_UPGRADE_EXTENDED_INFO4_ERROR;
extern const isc::log::MessageID DHCPSRV_MYSQL_UPGRADE_EXTENDED_INFO4_PAGE;
extern const isc::log::MessageID DHCPSRV_NOTYPE_DB;
extern const isc::log::MessageID DHCPSRV_NO_SOCKETS_OPEN;
extern const isc::log::MessageID DHCPSRV_OPEN_SOCKET_FAIL;
extern const isc::log::MessageID DHCPSRV_PGSQL_ADD_ADDR4;
extern const isc::log::MessageID DHCPSRV_PGSQL_ADD_ADDR6;
extern const isc::log::MessageID DHCPSRV_PGSQL_BEGIN_TRANSACTION;
extern const isc::log::MessageID DHCPSRV_PGSQL_COMMIT;
extern const isc::log::MessageID DHCPSRV_PGSQL_DB;
extern const isc::log::MessageID DHCPSRV_PGSQL_DEALLOC_ERROR;
extern const isc::log::MessageID DHCPSRV_PGSQL_DELETE_ADDR;
extern const isc::log::MessageID DHCPSRV_PGSQL_DELETE_EXPIRED_RECLAIMED4;
extern const isc::log::MessageID DHCPSRV_PGSQL_DELETE_EXPIRED_RECLAIMED6;
extern const isc::log::MessageID DHCPSRV_PGSQL_FATAL_ERROR;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET4;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET6;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_ADDR4;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_ADDR6;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_CLIENTID;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_DUID;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_EXPIRED4;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_EXPIRED6;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_HOSTNAME4;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_HOSTNAME6;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_HWADDR;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_IAID_DUID;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_IAID_SUBID_DUID;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_LINKADDR6;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_PAGE4;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_PAGE6;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_RELAYID4;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_RELAYID6;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_REMOTEID4;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_REMOTEID6;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_SUBID4;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_SUBID6;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_SUBID_CLIENTID;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_SUBID_HWADDR;
extern const isc::log::MessageID DHCPSRV_PGSQL_GET_VERSION;
extern const isc::log::MessageID DHCPSRV_PGSQL_HOST_DB;
extern const isc::log::MessageID DHCPSRV_PGSQL_HOST_DB_GET_VERSION;
extern const isc::log::MessageID DHCPSRV_PGSQL_HOST_DB_READONLY;
extern const isc::log::MessageID DHCPSRV_PGSQL_HOST_DB_RECONNECT_ATTEMPT_FAILED;
extern const isc::log::MessageID DHCPSRV_PGSQL_HOST_DB_RECONNECT_ATTEMPT_SCHEDULE;
extern const isc::log::MessageID DHCPSRV_PGSQL_HOST_DB_RECONNECT_FAILED;
extern const isc::log::MessageID DHCPSRV_PGSQL_LEASE_DB_RECONNECT_ATTEMPT_FAILED;
extern const isc::log::MessageID DHCPSRV_PGSQL_LEASE_DB_RECONNECT_ATTEMPT_SCHEDULE;
extern const isc::log::MessageID DHCPSRV_PGSQL_LEASE_DB_RECONNECT_FAILED;
extern const isc::log::MessageID DHCPSRV_PGSQL_NEGATIVE_LEASES_STAT;
extern const isc::log::MessageID DHCPSRV_PGSQL_NO_TLS_SUPPORT;
extern const isc::log::MessageID DHCPSRV_PGSQL_ROLLBACK;
extern const isc::log::MessageID DHCPSRV_PGSQL_START_TRANSACTION;
extern const isc::log::MessageID DHCPSRV_PGSQL_TLS_SUPPORT;
extern const isc::log::MessageID DHCPSRV_PGSQL_UPDATE_ADDR4;
extern const isc::log::MessageID DHCPSRV_PGSQL_UPDATE_ADDR6;
extern const isc::log::MessageID DHCPSRV_PGSQL_UPGRADE_BINARY_ADDRESS6;
extern const isc::log::MessageID DHCPSRV_PGSQL_UPGRADE_BINARY_ADDRESS6_ERROR;
extern const isc::log::MessageID DHCPSRV_PGSQL_UPGRADE_BINARY_ADDRESS6_PAGE;
extern const isc::log::MessageID DHCPSRV_PGSQL_UPGRADE_EXTENDED_INFO4;
extern const isc::log::MessageID DHCPSRV_PGSQL_UPGRADE_EXTENDED_INFO4_ERROR;
extern const isc::log::MessageID DHCPSRV_PGSQL_UPGRADE_EXTENDED_INFO4_PAGE;
extern const isc::log::MessageID DHCPSRV_QUEUE_NCR;
extern const isc::log::MessageID DHCPSRV_QUEUE_NCR_FAILED;
extern const isc::log::MessageID DHCPSRV_QUEUE_NCR_SKIP;
extern const isc::log::MessageID DHCPSRV_SUBNET4O6_SELECT_FAILED;
extern const isc::log::MessageID DHCPSRV_SUBNET4_SELECT_BY_ADDRESS_NO_MATCH;
extern const isc::log::MessageID DHCPSRV_SUBNET4_SELECT_BY_INTERFACE_NO_MATCH;
extern const isc::log::MessageID DHCPSRV_SUBNET4_SELECT_BY_RELAY_ADDRESS_NO_MATCH;
extern const isc::log::MessageID DHCPSRV_SUBNET4_SELECT_NO_RAI_OPTIONS;
extern const isc::log::MessageID DHCPSRV_SUBNET4_SELECT_NO_RELAY_ADDRESS;
extern const isc::log::MessageID DHCPSRV_SUBNET4_SELECT_NO_USABLE_ADDRESS;
extern const isc::log::MessageID DHCPSRV_SUBNET6_SELECT_BY_ADDRESS_NO_MATCH;
extern const isc::log::MessageID DHCPSRV_SUBNET6_SELECT_BY_INTERFACE_ID_NO_MATCH;
extern const isc::log::MessageID DHCPSRV_SUBNET6_SELECT_BY_INTERFACE_NO_MATCH;
extern const isc::log::MessageID DHCPSRV_TIMERMGR_CALLBACK_FAILED;
extern const isc::log::MessageID DHCPSRV_TIMERMGR_REGISTER_TIMER;
extern const isc::log::MessageID DHCPSRV_TIMERMGR_RUN_TIMER_OPERATION;
extern const isc::log::MessageID DHCPSRV_TIMERMGR_START_TIMER;
extern const isc::log::MessageID DHCPSRV_TIMERMGR_STOP_TIMER;
extern const isc::log::MessageID DHCPSRV_TIMERMGR_UNREGISTER_ALL_TIMERS;
extern const isc::log::MessageID DHCPSRV_TIMERMGR_UNREGISTER_TIMER;
extern const isc::log::MessageID DHCPSRV_UNEXPECTED_NAME;
extern const isc::log::MessageID DHCPSRV_UNKNOWN_DB;

} // namespace dhcp
} // namespace isc

#endif // DHCPSRV_MESSAGES_H
