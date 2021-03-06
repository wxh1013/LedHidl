#define LOG_TAG "LedService"

#include <log/log.h>
#include "ledImpl.h"

namespace android {
namespace hardware {
namespace led {
namespace V1_0 {
namespace implementation {

ledImpl::ledImpl() {
	state = LedStatus::LED_BAD_VALUE;
	ALOGE("ledImpl Init status:%d", state);
}

Return<void> ledImpl::on() {
	state = LedStatus::LED_ON;
	ALOGE("ledImpl on status:%d", state);
    return Void();
}

Return<void> ledImpl::off() {
	state = LedStatus::LED_OFF;
	ALOGE("ledImpl off status:%d", state);	
    return Void();
}

Return<LedStatus>  ledImpl::get() {
	return state;
}
Return<int32_t> ledImpl::set(LedStatus val) {
	if(val == LedStatus::LED_OFF || val == LedStatus::LED_ON)
		state = val;
	else
		return -1;
	return 0;
}

Return<void> ledImpl::getBrightnessRange(getBrightnessRange_cb _hidl_cb)
{
	ALOGE("ledImpl getBrightnessRange ");
	BrightnessRange range;
	range.max = 100;
	range.min = 1;
	_hidl_cb(true,range);
	return Void();
	
}
  
Return<bool> ledImpl::setBrightnessValue(const hidl_vec<int32_t>& range)
{
	ALOGE("ledImpl getBrightnessValue ");
	auto iter = range.begin();
	ALOGE("ledImpl getBrightnessValue range.begin: %d",*iter);
	iter = range.end();
	ALOGE("ledImpl getBrightnessValue range.end: %d",*iter);
	ALOGE("ledImpl getBrightnessValue range.size: %zu",range.size());
	return true;
}

ILed* HIDL_FETCH_ILed(const char * /*name*/) {
	ALOGE("ledImpl HIDL_FETCH_ILed ");	
    return new ledImpl();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace led
}  // namespace hardware
}  // namespace android