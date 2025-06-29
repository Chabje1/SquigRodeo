function wrapCallback  (cb) {
    return function(event) {
        cb.opCall(event);
    }
};