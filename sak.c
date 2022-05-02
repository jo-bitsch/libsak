#include "PCSC/ifdhandler.h"

/**
 * @brief start the reader thread
 * 
 * TODO: potentially use the device name as the state directory, as of which devices are paired.
 * 
 * @param Lun 
 * @param DeviceName 
 * @return RESPONSECODE 
 */
RESPONSECODE IFDHCreateChannelByName(DWORD Lun, LPSTR DeviceName)
{
    return IFD_SUCCESS;
}

/**
 * @brief interact with the reader library, not necessarily with the ICC
 * 
 * TODO: we might deal with the PIN PAD capabilities here.
 * 
 * @param Lun 
 * @param dwControlCode 
 * @param TxBuffer 
 * @param TxLength 
 * @param RxBuffer 
 * @param RxLength 
 * @param pdwBytesReturned 
 * @return RESPONSECODE 
 */
RESPONSECODE IFDHControl(DWORD Lun, DWORD dwControlCode, PUCHAR
	TxBuffer, DWORD TxLength, PUCHAR RxBuffer, DWORD RxLength,
	LPDWORD pdwBytesReturned)
{
    return IFD_SUCCESS;
}


/**
 * @brief this is deprecated and will not be used.
 * 
 * @param Lun 
 * @param Channel 
 * @return RESPONSECODE 
 */
RESPONSECODE IFDHCreateChannel(DWORD Lun, DWORD Channel)
{
    return IFD_NO_SUCH_DEVICE;
}

/**
 * @brief close down everything just before shutdown of pcscd
 * 
 * @param Lun 
 * @return RESPONSECODE 
 */
RESPONSECODE IFDHCloseChannel(DWORD Lun)
{
    return IFD_SUCCESS;
}

/**
 * @brief 
 * 
 * TODO: deal with all the threading things here. Make callbacks to stop threads available here.
 *       like: TAG_IFD_POLLING_THREAD_WITH_TIMEOUT
 * 
 * @param Lun 
 * @param Tag 
 * @param Length 
 * @param Value 
 * @return RESPONSECODE 
 */
RESPONSECODE IFDHGetCapabilities(DWORD Lun, DWORD Tag, PDWORD Length, PUCHAR Value)
{
    return IFD_SUCCESS;
}

/**
 * @brief probably not needed
 * 
 * @param Lun 
 * @param Tag 
 * @param Length 
 * @param Value 
 * @return RESPONSECODE 
 */
RESPONSECODE IFDHSetCapabilities(DWORD Lun, DWORD Tag, DWORD Length, PUCHAR Value)
{
    return IFD_NOT_SUPPORTED;
}

/**
 * @brief probably not needed
 * 
 * @param Lun 
 * @param Protocol 
 * @param Flags 
 * @param PTS1 
 * @param PTS2 
 * @param PTS3 
 * @return RESPONSECODE 
 */
RESPONSECODE IFDHSetProtocolParameters(DWORD Lun, DWORD Protocol, UCHAR Flags,
	UCHAR PTS1, UCHAR PTS2, UCHAR PTS3)
{
    return IFD_NOT_SUPPORTED;
}

/**
 * @brief power up and down the ICC if possible
 * 
 * @param Lun 
 * @param Action 
 * @param Atr 
 * @param AtrLength 
 * @return RESPONSECODE 
 */
RESPONSECODE IFDHPowerICC(DWORD Lun, DWORD Action, PUCHAR Atr, PDWORD
	AtrLength)
{
    return IFD_SUCCESS;
}

/**
 * @brief exchange APDUs with the ICC
 * 
 * @param Lun 
 * @param SendPci 
 * @param TxBuffer 
 * @param TxLength 
 * @param RxBuffer 
 * @param RxLength 
 * @param RecvPci 
 * @return RESPONSECODE 
 */
RESPONSECODE IFDHTransmitToICC(DWORD Lun, SCARD_IO_HEADER SendPci,
	PUCHAR TxBuffer, DWORD TxLength, PUCHAR RxBuffer, PDWORD
	RxLength, PSCARD_IO_HEADER RecvPci)
{
    return IFD_SUCCESS;
}

/**
 * @brief inform pcscd of card presence.
 * 
 * @param Lun 
 * @return RESPONSECODE 
 */
RESPONSECODE IFDHICCPresence(DWORD Lun)
{
    return IFD_ICC_NOT_PRESENT;
}
