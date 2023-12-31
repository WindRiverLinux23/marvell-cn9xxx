do_image_wic[postfuncs] += "marvell_cn96xx_wic"

BOOT_IMAGE_DIR ?= ""
BOOT_IMAGE ?= "octeontx-bootfs-uboot-t96.img"

marvell_cn96xx_wic() {
    if [ -f ${BOOT_IMAGE_DIR}/${BOOT_IMAGE} ]; then
	cp ${BOOT_IMAGE_DIR}/${BOOT_IMAGE} ${DEPLOY_DIR_IMAGE}/
    else
	touch ${DEPLOY_DIR_IMAGE}/${BOOT_IMAGE}
    fi
    dd if=${DEPLOY_DIR_IMAGE}/${BOOT_IMAGE} of=${IMGDEPLOYDIR}/${IMAGE_LINK_NAME}.wic bs=512 seek=128 skip=128 conv=fsync,notrunc
}
